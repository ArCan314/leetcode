#include <vector>
#include <map>

class Solution
{
public:
    int subarraySum(std::vector<int> &nums, int k)
    {
        if (!nums.size())
            return 0;
        std::map<int, int> map;
        map[0] = 1;
        int sum = 0, res = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if (int diff = sum - k; map.find(diff) != map.end())
            {
                res += map[diff];
            }
            map[sum]++;
        }
        return res;
    }
};