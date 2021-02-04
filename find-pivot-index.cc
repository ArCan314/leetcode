#include <vector>
#include <numeric>

class Solution {
public:
    int pivotIndex(const std::vector<int>& nums) 
    {
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        int partial_sum = 0;
        int res = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (partial_sum == sum - partial_sum - nums[i])
            {
                res = i;
                break;
            }
            partial_sum += nums[i];
        }
        return res;
    }
};