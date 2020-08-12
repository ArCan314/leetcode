#include <vector>
#include <algorithm>

class Solution
{
public:
    int hIndex(std::vector<int> &citations)
    {
        return hIndexSort(citations);
    }

    int hIndexSort(std::vector<int> &citations)
    {
        std::sort(citations.begin(), citations.end());
        if (!citations.size())
            return 0;
        
        int h_res = 0;
        if (citations.size() == 1)
            h_res = citations[0];

        for (int i = citations.size() - 1; i > 0; i--)
        {
            int h_now = citations.size() - i;
            if (citations[i] >= h_now && citations[i - 1] <= h_now)
                h_res = std::max(h_now, h_res);
        }
        return h_res;
    }
};