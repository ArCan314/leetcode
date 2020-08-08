#include <vector>
#include <unordered_map>

class Solution
{
public:
    int singleNumber(std::vector<int> &nums)
    {
        return singleNumberMap(nums);
    }

    int singleNumberMap(std::vector<int> &nums) // time: O(n), with extra memory use
    {
        std::unordered_map<int, int> map;
        for (const auto num : nums)
            map[num]++;
        for (const auto [num, freq] : map)
            if (freq == 1)
                return num;
        return 0;
    }
};