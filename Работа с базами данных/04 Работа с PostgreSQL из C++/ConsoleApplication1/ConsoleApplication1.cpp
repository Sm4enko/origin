#include <iostream>
#include <pqxx/pqxx>

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

    void insertData(const std::string& firstName, const std::string& lastName, const std::string& phoneNumber, const std::vector<std::string>& email) {
        pqxx::work txn(*connection);
        pqxx::result result = txn.prepared("stmt", "INSERT INTO people (first_name, last_name, phone_number, address) VALUES ($1, $2, $3, $4)")(
            firstName)(lastName)(phoneNumber)(email);
        txn.commit();
    }

    void updateData(int id, const std::string& firstName, const std::string& lastName, const std::string& phoneNumber, const std::vector<std::string>& email) {
        pqxx::work txn(*connection);
        pqxx::result result = txn.prepared("stmt", "UPDATE people SET first_name = $2, last_name = $3, phone_number = $4, address = $5 WHERE id = $1")(
            id)(firstName)(lastName)(phoneNumber)(email);
        txn.commit();
    }

    void deleteData(int id) {
        pqxx::work txn(*connection);
        pqxx::result result = txn.prepared("stmt", "DELETE FROM people WHERE id = $1")(id);
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
        std::vector<std::string> email = { "123 Main St", "456 Elm St" };
        db.insertData("John", "Doe", "+phoneNumber", email);
        db.updateData(1, "Jane", "Doe", "+phoneNumber", email);

        // Query data
        pqxx::result result = db.queryData("SELECT * FROM people");
        for (const pqxx::tuple& row : result) {
            std::cout << "ID: " << row["id"].as<int>() << ", First Name: " << row["first_name"].as<std::string>() <<
                ", Last Name: " << row["last_name"].as<std::string>() << ", Phone Number: " << row["phone_number"].as<std::string>() <<
                ", Address: " << row["address"].as<std::string>() << std::endl;
        }
        db.deleteData(1);
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
