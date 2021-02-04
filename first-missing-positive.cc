#include <vector>
#include <algorithm>

class Solution
{
public:
    int firstMissingPositive(std::vector<int> &nums)
    {
        return firstMissingPositiveSort(nums);
    }

    int firstMissingPositiveSort(std::vector<int> &nums)
    {
        std::sort(nums.begin(), nums.end());
        int res = 1;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
            {
                if (nums[i] == res)
                {
                    while (i < nums.size() && nums[i] == res)
                        i++;
                    i--;
                    res++;
                }
                else
                    break;
            }
        }
        return res;
    }
};