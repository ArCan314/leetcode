#include <vector>
#include <algorithm>

class Solution
{
public:
    int eraseOverlapIntervals(std::vector<std::vector<int>> &intervals)
    {
        std::sort(intervals.begin(), intervals.end(), 
            [](auto &a, auto &b) 
            {
                if (a[0] != b[0])
                    return a[0] < b[0];
                else
                    return a[1] < b[1];
            });

        int cnt = 0;
        int right = 0;

        for (const auto &interval : intervals)
            right = std::min(right, interval[0]);

        for (const auto &interval : intervals)
            if (interval[0] < right)
            {
                right = std::min(right, interval[1]);
            }
            else
            {
                cnt++;
                right = interval[1];
            }

        return intervals.size() - cnt;
    }
};