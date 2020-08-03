#include <vector>
#include <unordered_map>

class Solution {
public:
    int majorityElement(std::vector<int>& nums) 
    {
        std::unordered_map<int, int> dict;
        for (const int num : nums)
            if (int i = ++dict[num]; i > nums.size() / 2)
                return num;
        return 0;
    }
};