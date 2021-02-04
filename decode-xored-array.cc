#include <vector>

class Solution
{
public:
    std::vector<int> decode(std::vector<int> &encoded, int first)
    {
        std::vector<int> res(1, first);
        for (int i = 0; i < encoded.size(); i++)
            res.push_back(encoded[i] ^ res[i]);
        return res;
    }
};