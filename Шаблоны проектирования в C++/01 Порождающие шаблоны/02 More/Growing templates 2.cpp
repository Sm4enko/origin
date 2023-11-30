#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <type_traits>

class SqlSelectQueryBuilder {
public:
    SqlSelectQueryBuilder() : selectColumns({ "*" }), fromTable("") {}

    SqlSelectQueryBuilder& AddColumn(const std::string& cols) {
        selectColumns.push_back(cols);
        return *this;
    }

    SqlSelectQueryBuilder& AddColumns(const std::vector<std::string>& cols) noexcept {
        selectColumns.insert(selectColumns.end(), cols.begin(), cols.end());
        return *this;
    }

    SqlSelectQueryBuilder& AddFrom(const std::string& table) {
        fromTable = table;
        return *this;
    }

    SqlSelectQueryBuilder& AddWhere(const std::string& column, const std::string& value) {
        whereClauses.push_back(column + "=" + value);
        return *this;
    }

    SqlSelectQueryBuilder& AddWhere(const std::map<std::string, std::string>& qq) noexcept {
        for (const auto& pair : qq) {
            whereClauses.push_back(pair.first + "=" + pair.second);
        }
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
    SqlSelectQueryBuilder query_builder;
    query_builder.AddColumns({ "name", "phone" });
    query_builder.AddFrom("students");
    query_builder.AddWhere("id", "42").AddWhere("name", "John");

    query_builder.AddWhere({ {"age", "25"}, {"city", "New York"} });

    auto result = query_builder.Create();
    static_assert(std::is_same_v<decltype(result), std::string>,
        "Не совпадает тип запроса");

    return 0;
}
