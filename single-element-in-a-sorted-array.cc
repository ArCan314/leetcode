#include <vector>

class Solution
{
public:
    int singleNonDuplicate(std::vector<int> &nums)
    {
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            int mid = (l + r) / 2;
            if (mid > l && nums[mid - 1] == nums[mid])
                mid--;
            // std::cout << l << ", " << r << ", " << mid << std::endl;
            if ((mid - l) % 2)
                r = mid - 1;
            else
            {
                if (mid  < r && nums[mid + 1] == nums[mid])
                    l = mid + 2;
                else
                    l = r = mid;
            }
        }
        return nums[l];
    }
};