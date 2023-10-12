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
        exec(sql);
    }

    void insertData(const std::string& firstName, const std::string& lastName, const std::string& phoneNumber, const std::vector<std::string>& email) {
        std::string sql = "INSERT INTO people (first_name, last_name, phone_number, address) VALUES ($1, $2, $3, $4)";
        exec(sql, firstName, lastName, phoneNumber, email);
    }

    void updateData(int id, const std::string& firstName, const std::string& lastName, const std::string& phoneNumber, const std::vector<std::string>& email) {
        std::string sql = "UPDATE people SET first_name = $2, last_name = $3, phone_number = $4, address = $5 WHERE id = $1";
        exec(sql, id, firstName, lastName, phoneNumber, email);
    }

    void deleteData(int id) {
        std::string sql = "DELETE FROM people WHERE id = $1";
        exec(sql, id);
    }

    pqxx::result queryData(const std::string& selectQuery) {
        return query(selectQuery);
    }

private:
    pqxx::connection* connection;

    exec("INSERT INTO people (first_name, last_name, phone_number, email) VALUES ($1, $2, $3, $4)", firstName, lastName, phoneNumber, email);

    pqxx::result result = query("SELECT * FROM people WHERE first_name = $1 AND last_name = $2", firstName, lastName);


int main() {
    TransactionBase db;

    try {
        pqxx::work txn(*db.connection);

        // Create a prepared statement for later use
        txn.prepared("stmt", "INSERT INTO people (first_name, last_name, phone_number, address) VALUES ($1, $2, $3, $4)");
        txn.prepared("stmt", "UPDATE people SET first_name = $2, last_name = $3, phone_number = $4, address = $5 WHERE id = $1");
        txn.prepared("stmt", "DELETE FROM people WHERE id = $1");

        txn.commit();
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    // Create the 'people' table
    db.createTable();

    // Insert some data
    std::vector<std::string> email = { "123 Main St", "456 Elm St" };
    db.insertData("John", "Doe", phoneNumber, "sldfjl@dsjfl.dsjalfj");

    // Update data
    db.updateData(1, "Jane", "Doe", "+phoneNumber", "jsdlfjl@gjalsdjfgls.coaf");

    // Query data
    pqxx::result result = db.queryData("SELECT * FROM people");
    for (const pqxx::tuple& row : result) {
        std::cout << "ID: " << row["id"].as<int>() << ", First Name: " << row["first_name"].as<std::string>() <<
            ", Last Name: " << row["last_name"].as<std::string>() << ", Phone Number: " << row["phone_number"].as<std::string>() <<
            ", Address: " << row["address"].as<std::string>() << std::endl;
    }

    // Delete data
    db.deleteData(1);

    return 0;
}