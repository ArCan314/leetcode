#include <vector>
#include <algorithm>
#include <unordered_set>

class Solution
{
public:
    std::vector<int> findDuplicates(std::vector<int> &nums)
    {
        return findDuplicatesOpt(nums);
    }

    std::vector<int> findDuplicatesOpt(std::vector<int> &nums) // space: O(1), time: O(n)
    {
        std::vector<int> res;
        for (int i = 0; i < nums.size(); i++)
        {
            int temp = std::abs(nums[i]) - 1;
            if (nums[temp] > 0) // first appearance
                nums[temp] *= -1;
            else if (nums[temp] < 0) // second appearance
                res.push_back(temp + 1);
        }
        return res;
    }

    std::vector<int> findDuplicatesSort(std::vector<int> &nums) // space: O(1), time: O(n logn)
    {
        std::sort(nums.begin(), nums.end());
        std::vector<int> res;
        for (int i = 1; i < nums.size(); i++)
            if (nums[i] == nums[i - 1])
                res.push_back(nums[i]);
        return res;
    }

    std::vector<int> findDuplicatesHashset(std::vector<int> &nums) // time: O(n)
    {
        std::unordered_set<int> set;
        std::vector<int> res;
        for (const int num : nums)
            if (auto i = set.find(num); i != set.end())
                res.push_back(*i);
            else
                set.insert(num);
        return res;
    }
};