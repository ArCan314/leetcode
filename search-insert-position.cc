#include <vector>

class Solution
{
public:
    int searchInsert(std::vector<int> &nums, int target)
    {
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            int mid = (l + r) / 2;
            if (nums[mid] < target)
                l = mid + 1;
            else if (nums[mid] > target)
                r = mid - 1;
            else
                return mid; // find target at index mid
        }
        // std::cout << target << ", l: " << l << ", r: " << r << ", nums[l]: " << nums[l] << std::endl;
        return (nums[l] < target) ? l + 1 : l;
    }
};