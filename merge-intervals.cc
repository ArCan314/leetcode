#include <vector>
#include <algorithm>

class Solution
{
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>> &intervals)
    {
        auto comp = [](const std::vector<int> &a, const std::vector<int> &b) { return a.front() < b.front(); };

        if (!intervals.size())
        {
            return {};
        }

        std::sort(intervals.begin(), intervals.end(), comp);

        std::vector<std::vector<int>> res;

        int l = intervals.front().front(), r = intervals.front().back();

        for (int i = 1; i < intervals.size(); i++)
        {
            if (r >= intervals.at(i).at(1))
            {
                continue;
            }
            else if (r >= intervals.at(i).at(0))
            {
                r = intervals.at(i).at(1);
            }
            else
            {
                res.push_back({l,r});
                l = intervals.at(i).at(0);
                r = intervals.at(i).at(1);
            }
        }

        res.push_back({l,r});
        return res;
    }
};