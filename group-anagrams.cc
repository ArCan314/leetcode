#include <string>
#include <vector>
#include <array>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <iostream>

class Solution
{
public:
    std::string gen_str(const std::array<int, 26> &freq)
    {
        constexpr char div_char = ' ';
        std::string res;
        for (int i = 0; i < freq.size(); i++)
        {
            res += std::to_string(freq[i]);
            res += div_char;
        }
        return res;
    }

    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string> &strs)
    {
        std::array<int, 26> freq{};
        std::unordered_map<std::string, int> m;
        std::string temp;
        std::vector<std::vector<std::string>> res;

        for (auto &str : strs)
        {
            for (auto &i : freq)
                i = 0;

            for (const auto &c : str)
                freq[c - 'a']++;
            temp = gen_str(freq);
            // std::cout << temp << ", " << str << std::endl;
            if (m.count(temp))
            {
                res[m[temp]].push_back(std::move(str));
            }
            else
            {
                m[temp] = res.size();
                res.push_back(std::vector<std::string>{std::move(str)});
            }
        }

        return res;
    }
};