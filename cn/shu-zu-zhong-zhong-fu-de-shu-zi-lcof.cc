#include <vector>
#include <unordered_set>
#include <algorithm>

class Solution
{
public:
    int findRepeatNumber(std::vector<int> &nums)
    {
        return findRepeatNumberSort(nums);
    }

    int findRepeatNumberSort(std::vector<int> &nums) // O(n^logn) modifies the array, constant memory
    {
        std::sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++)
            if (nums[i] == nums[i - 1])
                return nums[i];
        return 0;
    }

    int findRepeatNumberHashset(std::vector<int> &nums) // O(n) with extra memory usage
    {
        std::unordered_set<int> hash_set;
        for (const auto num : nums)
            if (!hash_set.insert(num).second)
                return num;
        return 0;
    }
};