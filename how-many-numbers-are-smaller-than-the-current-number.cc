#include <vector>
#include <algorithm>
#include <map>

class Solution
{
public:
    std::vector<int> smallerNumbersThanCurrent(std::vector<int> &nums)
    {
        std::map<int, int> freqs;
        std::map<int, int> highers;
        std::for_each(nums.begin(), nums.end(), [&](const auto i){ freqs[i]++; } );
        int accum = 0;
        for (const auto [num, freq] : freqs)
        {
            highers[num] = accum;
            accum += freq;
        }
        std::vector<int> res;
        std::for_each(res.begin(), res.end(), [&](const auto i) {res.push_back(highers[i]);});
        return res;
    }
};