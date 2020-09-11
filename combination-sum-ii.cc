#include <string>
#include <unordered_set>
#include <vector>
#include <algorithm>

class Solution
{
public:
    static std::string toString(std::vector<int> vec)
    {
        std::string temp;
        for (const auto num : vec)
            temp.append(std::to_string(num)).push_back('#');
        return temp;
    }

    static bool IsDup(std::vector<int> result, std::unordered_set<std::string> &combs)
    {
        std::sort(result.begin(), result.end());
        if (combs.insert(toString(result)).second)
            return false;
        return true;
    }

    void _combinationSum2(
        const std::vector<int> &candidates,
        std::vector<std::vector<int>> &results,
        std::unordered_set<std::string> &combs,
        std::vector<int> &cur_comb,
        int cur_ind,
        int tar)

    {
        if (!tar)
        {
            if (!IsDup(cur_comb, combs))
                results.push_back(cur_comb);
        }
        
        if (cur_ind == candidates.size())
            return;

        for (int i = cur_ind; i < candidates.size(); i++)
        {
            if (tar - candidates[i] >= 0)
            {
                cur_comb.push_back(candidates[i]);
                _combinationSum2(candidates, results, combs, cur_comb, i + 1, tar - candidates[i]);
                cur_comb.pop_back();
            }
            else
                break;
        }
    }

    std::vector<std::vector<int>> combinationSum2(std::vector<int> &candidates, int target)
    {
        std::sort(candidates.begin(), candidates.end());
        std::unordered_set<std::string> combs;
        std::vector<std::vector<int>> results;
        std::vector<int> result;
        _combinationSum2(candidates, results, combs, result, 0, target);
        return results;
    }
};