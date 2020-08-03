#include <vector>
#include <map>
#include <deque>
#include <algorithm>

class Solution
{
public:
    std::vector<int> findDiagonalOrder(std::vector<std::vector<int>> &nums)
    {
        std::vector<int> res;
        int max_size = 0;
        for (int i = 0; i < nums.size(); i++)
            max_size = std::max(max_size, static_cast<int>(nums[i].size()));
        std::vector<std::vector<int>> collect(max_size + nums.size() + 1);

        for (int i = 0; i < nums.size(); i++)
            for (int j =0; j < nums[i].size(); j++)
                collect[i+j].push_back(nums[i][j]);

        for (auto &v : collect)
        {
            std::reverse(v.begin(), v.end());
            res.insert(res.end(), v.begin(), v.end());
        }
        return res;
    }
};