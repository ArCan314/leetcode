#include <vector>
#include <unordered_set>

class Solution
{
public:
    bool containsDuplicate(std::vector<int> &nums)
    {
        std::unordered_set<int> num_set;
        num_set.insert(nums.begin(), nums.end());
        return num_set.size() != nums.size();
    }
};