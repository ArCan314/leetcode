#include <vector>
#include <numeric>

class Solution {
public:
    int missingNumber(std::vector<int>& nums) {
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        return nums.size() * (nums.size() + 1) / 2 - sum;
    }
};