#include <vector>
#include <iostream>

class Solution
{
public:
    std::vector<int> searchRange(std::vector<int> &nums, int target)
    {
        if (!nums.size())
            return {-1, -1};

        int l = 0, r = nums.size() - 1, left_ind = -1, right_ind = -1;

        while (l < r)
        {
            int mid = (r + l) / 2;
            // std::cout << l << ", " << mid << ", " << r << std::endl;
            if (nums[mid] < target)
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }

            if (l == r - 1)
            {
                if (nums[l] == target)
                {
                    r = l;
                }
                else
                {
                    l = r;
                }
            }
        }

        if (nums[l] != target)
        {
            return {-1, -1};
        }
        else
        {
            left_ind = l;
        }

        l = left_ind, r = nums.size() - 1;

        while (l < r)
        {
            int mid = (r + l) / 2;
            // std::cout << l << ", " << mid << ", " << r << std::endl;
            if (nums[mid] > target)
            {
                r = mid - 1;
            }
            else
            {
                l = mid;
            }

            if (l == r - 1)
            {
                if (nums[r] == target)
                {
                    l = r;
                }
                else
                {
                    r = l;
                }
            }
        }

        right_ind = r;
        return {left_ind, right_ind};
    }
};