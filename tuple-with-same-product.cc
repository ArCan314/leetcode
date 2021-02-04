#include <vector>
#include <unordered_map>

class Solution
{
public:
    int tupleSameProduct(std::vector<int> &nums)
    {
        return tupleSameProductHashMap(nums);
    }

    int tupleSameProductHashMap(std::vector<int> &nums)
    {
        std::unordered_map<int, int> freq;
        for (int i = 0; i < nums.size(); i++)
            for (int j = i + 1; j < nums.size(); j++)
                freq[nums[i] * nums[j]]++;

        int res = 0;
        for (const auto &[mul, f] : freq)
            if (f > 1)
                res += f * (f - 1) * 4;
        
        return res;
    }
};