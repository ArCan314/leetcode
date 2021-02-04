#include <vector>
#include <algorithm>

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) 
    {
        int slow, fast;
        slow = fast = 0;
        for (; fast < nums.size(); fast++)
        {
            if (nums[fast] != val)
                std::swap(nums[slow++], nums[fast]);
        }
        return slow;
    }
};