#include <vector>

class Solution
{
public:
    int findMin(std::vector<int> &nums)
    {
        return findMinBinarySearch(nums);
    }

    int findMinLinear(std::vector<int> &nums)
    {
        int res = nums[0];
        for (int i = 1; i < nums.size(); i++)
            if (nums[i] < nums[i - 1])
                return nums[i];
        return res;
    }

    int findMinBinarySearch(std::vector<int> &nums)
    {
        int res = nums[0];
        int l = 0, r = nums.size() - 1;

        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] > nums[r])
                l = mid + 1;
            else if (nums[mid] < nums[l])
                r = mid;
            else
                r--;
        }

        return nums[l];
    }
};