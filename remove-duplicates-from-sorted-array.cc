#include <vector>

class Solution
{
public:
    int removeDuplicates(std::vector<int> &nums)
    {
        if (nums.empty())
            return 0;

        int slow = 0, fast = 1;
        for (; fast < nums.size(); fast++)
            if (nums[fast] != nums[slow])
                nums[++slow] = nums[fast];
        return slow + 1;
    }
};