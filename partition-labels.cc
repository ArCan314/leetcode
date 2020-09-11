#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <set>
#include <map>

class Solution
{
public:
    std::vector<int> partitionLabels(std::string S)
    {
        std::map<char, std::pair<int, int>> intervals;
        for (int i = 0; i < S.size(); i++)
        {
            if (auto iter = intervals.find(S[i]); iter != intervals.end())
                iter->second.second = i;
            else
                intervals[S[i]] = {i, i}; 
        }

        std::vector<std::pair<int, int>> int_collect;
        for (const auto &[c, interval] : intervals)
            int_collect.push_back(interval);

        std::sort(int_collect.begin(), int_collect.end());

        std::vector<std::pair<int ,int>> final_intervals(1, int_collect.front());

        for (int i = 1; i < int_collect.size(); i++)
        {
            const auto [lb, ub] = int_collect[i];
            if (int &p_ub = final_intervals.back().second; lb < p_ub)
                p_ub = std::max(ub, p_ub);
            else
                final_intervals.push_back({lb, ub});
        }

        std::vector<int> result;

        for (const auto [lb, ub] : final_intervals)
            result.push_back(ub - lb + 1);

        return result;
    }
};