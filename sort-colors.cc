#include <vector>
#include <algorithm>

class Solution
{
public:
    void sortColors(std::vector<int> &nums)
    {
        int l = 0, r = nums.size() - 1, i = 0;

        while (i <= r)
        {
            if (nums[i] == 0)
            {
                std::swap(nums[i++], nums[l++]);
            }
            else if (nums[i] == 1)
            {
                i++;
            }
            else
            {
                std::swap(nums[i], nums[r--]);
            }
        }
    }
};