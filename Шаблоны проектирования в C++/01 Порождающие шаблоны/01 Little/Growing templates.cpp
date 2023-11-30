#include <iostream>
#include <vector>
#include <string>
#include <type_traits>

class SqlSelectQueryBuilder {
public:
    SqlSelectQueryBuilder() : selectColumns({ "*" }), fromTable("") {}

    SqlSelectQueryBuilder& AddColumn(const std::string& column) {
        selectColumns.push_back(column);
        return *this;
    }

    SqlSelectQueryBuilder& AddFrom(const std::string& table) {
        fromTable = table;
        return *this;
    }

    SqlSelectQueryBuilder& AddWhere(const std::string& col, const std::string& value) {
        whereClauses.push_back(col + "=" + value);
        return *this;
    }

    std::string Create() const {
        std::string query = "SELECT " + addColumns() + " FROM " + fromTable + addWhereClauses();
        std::cout << query << std::endl;
        return query;
    }

private:
    std::vector<std::string> selectColumns;
    std::string fromTable;
    std::vector<std::string> whereClauses;

    std::string addColumns() const {
        return (selectColumns.size() > 1) ? JoinStrings(selectColumns, ", ") : selectColumns[0];
    }

    std::string addWhereClauses() const {
        return (whereClauses.empty()) ? "" : " WHERE " + JoinStrings(whereClauses, " AND ");
    }

    std::string JoinStrings(const std::vector<std::string>& strings, const std::string& delimiter) const {
        std::string result;
        for (size_t i = 0; i < strings.size(); ++i) {
            result += strings[i];
            if (i < strings.size() - 1) {
                result += delimiter;
            }
        }
        return result;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    SqlSelectQueryBuilder query_builder;
    query_builder.AddColumn("name").AddColumn("phone");
    query_builder.AddFrom("students");
    query_builder.AddWhere("id", "42").AddWhere("name", "John");

    static_assert(std::is_same<decltype(query_builder.Create()), std::string>::value,
        "Не совпадает тип запроса");

    return 0;
}
