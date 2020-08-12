#include <vector>
#include <unordered_map>
#include <thread>

class Solution
{
public:
    int fourSumCount(std::vector<int> &A, std::vector<int> &B, std::vector<int> &C, std::vector<int> &D) // O(n^2)
    {

        std::unordered_map<int, int> map;
        int res = 0;

        for (const auto a : A)
            for (const auto b : B)
                map[a + b]++;

        for (const auto c : C)
            for (const auto d : D)
                if (auto iter = map.find(-c - d); iter != map.end())
                    res += iter->second;
        return res;
    }
};