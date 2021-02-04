#include <vector>
#include <algorithm>

class Solution
{
public:
    std::vector<std::vector<int>> insert(
        std::vector<std::vector<int>> &intervals,
        vector<int> &newInterval)
    {
        int l{}, r{static_cast<int>(intervals.size()) - 1};
        std::vector<std::vector<int>> res;

        for (int i = 0; i < intervals.size(); i++)
        {
            if (newInterval[0] <= intervals[i][1])
                break;
            else
                l++;
        }

        if (l == intervals.size())
        {
            res = intervals;
            res.push_back(newInterval);
            return res;
        }

        for (int i = intervals.size() - 1; i >= 0; i--)
        {
            if (newInterval[1] >= intervals[i][0])
                break;
            else
                r--;
        }

        if (r < 0)
        {
            std::vector<std::vector<int>> res;
            res.push_back(newInterval);
            std::for_each(intervals.begin(), intervals.end(), [&res](auto &vec) { res.push_back(vec); });
            return res;
        }

        if (l > r)
        {
            for (int i = 0; i <= r; i++)
                res.push_back(intervals[i]);
            res.push_back(newInterval);
            for (int i = l; i < intervals.size(); i++)
                res.push_back(intervals[i]);
            return res;
        }

        for (int i = 0; i < l; i++)
            res.push_back(intervals[i]);

        std::vector<int> temp = intervals[l];
        for (int i = l; i <= r; i++)
        {
            temp[0] = std::min(newInterval[0], std::min(intervals[i][0], temp[0]));
            temp[1] = std::max(newInterval[1], std::max(intervals[i][1], temp[1]));
        }

        res.push_back(temp);

        for (int i = r + 1; i < intervals.size(); i++)
            res.push_back(intervals[i]);

        return res;
    }
};