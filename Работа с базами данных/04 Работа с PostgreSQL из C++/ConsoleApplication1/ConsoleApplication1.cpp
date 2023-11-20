#include <iostream>
#include <pqxx/pqxx>
#include <vector>

namespace pqxx {
namespace prepare {
    class invocation {
    public:
       
    };
}
}

// Добавляем член "prepared" в класс pqxx::transaction<pqxx::read_committed, pqxx::write_policy::read_write>
template <>
class pqxx::transaction<pqxx::read_committed, pqxx::write_policy::read_write>::implementation {
public:
   
    pqxx::prepare::invocation prepared(const std::string& name) {
        return pqxx::prepare::invocation{*this, name};
    }

   
};

class TransactionBase {
public:
    TransactionBase() {
        connection = new pqxx::connection("dbname=mydb user=myuser password=mypassword hostaddr=127.0.0.1 port=5432");
    }

    ~TransactionBase() {
        delete connection;
    }

    void createTable() {
        std::string sql = "CREATE TABLE IF NOT EXISTS people ("
            "id serial PRIMARY KEY, "
            "first_name VARCHAR(50), "
            "last_name VARCHAR(50), "
            "phone_number VARCHAR(20), "
            "address TEXT[])";
        pqxx::work txn(*connection);
        txn.exec(sql);
        txn.commit();
    }

    void insertData(const std::string& firstName, const std::string& lastName, const std::string& phoneNumber, const std::vector<std::string>& address) {
        pqxx::work txn(*connection);
        pqxx::prepare::invocation invoc = txn.prepared("stmt");
        invoc("INSERT INTO people (first_name, last_name, phone_number, address) VALUES ($1, $2, $3, $4)",
            firstName)(lastName)(phoneNumber)(address);
        invoc.exec();
        txn.commit();
    }

    void updateData(int id, const std::string& firstName, const std::string& lastName, const std::string& phoneNumber, const std::vector<std::string>& address) {
        pqxx::work txn(*connection);
        pqxx::prepare::invocation invoc = txn.prepared("stmt");
        invoc("UPDATE people SET first_name = $2, last_name = $3, phone_number = $4, address = $5 WHERE id = $1",
            id)(firstName)(lastName)(phoneNumber)(address);
        invoc.exec();
        txn.commit();
    }

    void deleteData(int id) {
        pqxx::work txn(*connection);
        pqxx::prepare::invocation invoc = txn.prepared("stmt");
        invoc("DELETE FROM people WHERE id = $1", id);
        invoc.exec();
        txn.commit();
    }

    pqxx::result queryData(const std::string& selectQuery) {
        pqxx::work txn(*connection);
        return txn.exec(selectQuery);
    }

private:
    pqxx::connection* connection;
};

int main() {
    TransactionBase db;

    try {
        db.createTable();
        std::vector<std::string> address = { "123 Main St", "456 Elm St" };
        db.insertData("John", "Doe", "+phoneNumber", address);
        db.updateData(1, "Jane", "Doe", "+phoneNumber", address);

        pqxx::result result = db.queryData("SELECT * FROM people");
        for (const pqxx::tuple& row : result) {
            std::cout << "ID: " << row[0].as<int>() << ", First Name: " << row[1].as<std::string>() <<
                ", Last Name: " << row[2].as<std::string>() << ", Phone Number: " << row[3].as<std::string>() <<
                ", Address: " << row[4].as<std::string>() << std::endl;
        }
        db.deleteData(1);
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
