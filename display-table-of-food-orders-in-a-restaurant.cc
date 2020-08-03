#include <vector>
#include <string>
#include <map>
#include <set>

class Solution
{
public:
    std::vector<std::vector<std::string>> displayTable(std::vector<std::vector<std::string>> &orders)
    {
        std::map<int, std::map<std::string, int>> order_list;
        std::map<std::string, int> food_items;
        for (const auto &order : orders)
        {
            food_items[order[2]] = 0;
            order_list[std::stoi(order[1])][order[2]]++;
        }

        std::vector<std::vector<std::string>> res;
        res.push_back({});
        res.front().push_back("Table");
        int ind = 1;
        for (auto &food : food_items)
        {
            res.front().push_back(food.first);
            food.second = ind++;
        }

        for (const auto &order : order_list)
        {
            res.push_back({});
            res.back().resize(ind, "0");
            res.back()[0] = std::to_string(order.first);
            for (const auto &o : order.second)
            {
                res.back()[food_items[o.first]] = std::to_string(o.second);
            }
        }

        return res;
    }
};