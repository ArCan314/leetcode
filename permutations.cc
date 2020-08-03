#include <vector>
#include <algorithm>

class Solution
{
private:
    void _permute(std::vector<std::vector<int>> &res, std::vector<int> &nums, int now)
    {
        if (now == nums.size() - 1)
        {
            res.push_back(nums);
            return;
        }

        for (int i = now; i < nums.size(); i++)
        {
            std::swap(nums[now], nums[i]);
            _permute(res, nums, now + 1);
            std::swap(nums[now], nums[i]);
        }
    }

public:
    std::vector<std::vector<int>> permute(std::vector<int> &nums)
    {
        std::vector<std::vector<int>> res;
        _permute(res, nums, 0);
        return res;
    }
};