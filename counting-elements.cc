#include <vector>
#include <array>

class Solution
{
public:
    int countElements(const std::vector<int> &arr)
    {
        if (arr.size() < 2)
            return 0;

        std::array<int, 1001> freq{};
        for (int i = 0; i < arr.size(); i++)
            freq[arr[i]]++;

        int res = 0;
        for (int i = 0; i < freq.size() - 1; i++)
            if (freq[i+1])
                res += freq[i];

        return res;
    }
};