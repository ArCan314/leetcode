#include <vector>
#include <algorithm>

class Solution
{
public:
    int findLengthOfLCIS(std::vector<int> &nums)
    {
        if (!nums.size())
            return 0;

        int l = 0, r = 1;
        int res = 1;
        while (r < nums.size())
        {
            if (nums[r] <= nums[r - 1])
            {
                res = std::max(res, r - l);
                l = r;
            }
            r++;
        }
        res = std::max(res, r - l);
        return res;
    }
};