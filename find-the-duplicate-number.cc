#include <vector>
#include <algorithm>
#include <unordered_set>

class Solution
{
public:
    int findDuplicate(const std::vector<int> &nums)
    {
        return findDuplicateSort(nums);
    }

    int findDuplicateTrival(const std::vector<int> &nums) // O(n^2)
    {
        for (int i = 0; i < nums.size(); i++)
            for (int j = i + 1; j < nums.size(); j++)
                if (nums[j] == nums[i])
                    return nums[i];
        return -1;
    }

    int findDuplicateSort(const std::vector<int> &nums) // O(n logn)
    {
        auto copy = nums;
        std::sort(copy.begin(), copy.end());
        for (int i = 1; i < copy.size(); i++)
            if (copy[i] == copy[i - 1])
                return copy[i];
        return -1;
    }

    int findDuplicateSet(const std::vector<int> &nums) // O(n)
    {
        std::unordered_set<int> hashset;
        for (const auto num : nums)
            if (!hashset.insert(num).second)
                return num;
        return -1;
    }
};