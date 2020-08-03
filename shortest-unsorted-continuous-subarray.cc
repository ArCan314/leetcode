#include <vector>
#include <algorithm>

class Solution
{
public:
    int findUnsortedSubarray(std::vector<int> &nums)
    {
        if (nums.size() <= 1)
        {
            return 0;
        }

        int l = 0, r = -1;
        auto nums_sort = nums;

        std::sort(nums_sort.begin(), nums_sort.end());

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != nums_sort[i])
            {
                l = i;
                break;
            }
        }

        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (nums[i] != nums_sort[i])
            {
                r = i;
                break;
            }
        }

        return r - l + 1;
    }
};