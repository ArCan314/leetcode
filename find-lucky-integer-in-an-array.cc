#include <vector>
#include <unordered_map>
#include <algorithm>
#include <optional>

class Solution {
public:
    int findLucky(const std::vector<int>& arr) {
        std::unordered_map<int, int> freq;
        std::for_each(arr.begin(), arr.end(), 
                [&](const int num)
                {
                    freq[num] += 1;
                });

        std::optional<int> res{std::nullopt};
        std::for_each(freq.begin(), freq.end(), 
                [&](const auto &in)
                {
                    if (in.first == in.second)
                        res = res.has_value() ? std::max(in.first, res.value()) : in.first; 
                });

        return res.value_or(-1);
    }
};