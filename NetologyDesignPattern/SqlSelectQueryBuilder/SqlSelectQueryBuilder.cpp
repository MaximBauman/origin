#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>


class SqlSelectQueryBuilder {
public:
    SqlSelectQueryBuilder& AddColumn(const std::string& s_value){
        columns.push_back(s_value);
        return *this;
    }
    SqlSelectQueryBuilder& AddFrom(const std::string& table) {
        t_name = table;
        return *this;
    }
    SqlSelectQueryBuilder& AddWhere(const std::string& key, const std::string& value) {
        key_value_map[key] = value;
        return *this;
    }

    

    std::string QueryConstruction() {
        std::string query = " SELECT ";
        if (columns.empty()) {
            query += "*";
        }
        else {
            bool first = true;
            for (const auto& col : columns) {
                if (!first) query += ", ";
                query += col;
                first = false;
            }
        }

        query += " FROM " + t_name;

        if (!key_value_map.empty()) {
            query += " WHERE ";
            bool first = true;
            for (const auto& [key, value] : key_value_map) {
                if (!first) query += " AND ";
                query += key + "=" + value;
                first = false;
            }
        }

        query += ";";
        return query;
    };

    ~SqlSelectQueryBuilder() {};
private: 
    std::vector<std::string> columns;
    std::string t_name;
    std::unordered_map<std::string, std::string> key_value_map;
};

int main()
{
    std::cout << "Hello!\n";

    SqlSelectQueryBuilder query_builder;

    query_builder.AddColumn("name").AddColumn("phone");
    query_builder.AddFrom("managers");
    query_builder.AddWhere("id", "1").AddWhere("name", "Max");

    std::string result = query_builder.QueryConstruction();
    std::cout << "Generated Query:\n" << result << std::endl;

    return 0;
}


