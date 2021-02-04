#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution
{
public:
    int hash(const std::vector<int> &pair)
    {
        int a = std::max(pair[0], pair[1]);
        int b = std::min(pair[0], pair[1]);
        return (b + 1) * 10 + a;        
    }

    int numEquivDominoPairs(std::vector<std::vector<int>> &dominoes)
    {
        std::unordered_map<int, int> freq;
        for (const auto &domino : dominoes)
            freq[hash(domino)]++;

        int res = 0;
        for (const auto &[hash_val, count]: freq)
            if (count > 1)
                res += count * (count - 1) / 2;
        return res;
    }
};