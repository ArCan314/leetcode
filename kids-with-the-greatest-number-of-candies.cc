#include <vector>
#include <algorithm>

class Solution
{
public:
    std::vector<bool> kidsWithCandies(std::vector<int> &candies, int extraCandies)
    {
        auto max = std::max_element(candies.begin(), candies.end());
        std::vector<bool> res;
        std::for_each(candies.begin(), candies.end(), [&](const auto candy) { res.push_back((candy + extraCandies) >= *max); } );
        return res;
    }
};