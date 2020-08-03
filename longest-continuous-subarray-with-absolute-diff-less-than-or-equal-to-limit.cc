#include <vector>
#include <queue>

class Solution
{
public:
    int longestSubarray(std::vector<int> &nums, int limit)
    {
        int min = nums.front(), max = min;
        int l = 0, r = 0;
        int res = 1;
        while (r < nums.size())
        {
            max = std::max(max, nums[r]);
            min = std::min(min, nums[r]);
            std::cout << "dl: " << l << ", r: " << r << ", min: " << min << ", max: " << max << std::endl;
            if (max - min <= limit)
            {
                res = std::max(res, r - l + 1);
                r++;
            }
            else
            {
                int i = l;
                for (; i < r; i++)
                {
                    if (nums[i] == max)
                    {
                        max = nums[i + 1];
                        for (int j = i + 1; j <= r; j++)
                            max = std::max(max, nums[j]);
                        l = i + 1;
                    }
                    else if (nums[i] == min)
                    {
                        min = nums[i + 1];
                        for (int j = i + 1; j <= r; j++)
                            min = std::min(nums[j], min);
                        l = i + 1;
                    }
                    else if (max - min <= limit)
                    {
                        l = i;
                        break;
                    }
                }
            }
            std::cout << "l: " << l << ", r: " << r << ", min: " << min << ", max: " << max << std::endl;
        }
        return res;
    }
};