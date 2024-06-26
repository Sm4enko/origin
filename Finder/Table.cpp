#include "Table.h"
#include <pqxx/pqxx>
#include <iostream>

void create_table() {
    try {
        pqxx::connection conn("dbname=testdb user=postgres password=1520L host=127.0.0.1 port=5432");
        pqxx::work txn(conn);
        txn.exec("CREATE TABLE IF NOT EXISTS word_data (word TEXT PRIMARY KEY, frequency INTEGER)");
        txn.commit();
        std::cout << "Table here" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void retrieve_data() {
    try {
        pqxx::connection conn("dbname=testdb user=postgres password=1520L host=127.0.0.1 port=5432");
        pqxx::work txn(conn);
        pqxx::result result = txn.exec("SELECT word, frequency FROM word_data");
        std::cout << "Retrieved data:" << std::endl;
        for (const auto& row : result) {
            std::cout << "Word: " << row["word"].c_str() << ", Frequency: " << row["frequency"].as<int>() << std::endl;
        }
        txn.commit();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
