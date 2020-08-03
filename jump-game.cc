#include <vector>
#include <algorithm>

class Solution
{
public:
    bool canJump(std::vector<int> &nums)
    {
        int l = 0, r = 0;
        while (l <= r && r < nums.size())
        {
            r = std::max(r, nums[l] + l);
            l++;
        }
        return r >= static_cast<int>(nums.size() - 1);
    }
};