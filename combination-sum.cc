#include <vector>
#include <algorithm>

class Solution
{
private:
    std::vector<std::vector<int>> res;

    void _combinationSum(int target, int now, std::vector<int> &path, const std::vector<int> &candidates)
    {
        if (target == 0)
        {
            res.push_back(path);
            return;
        }

        for (int i = now; i < candidates.size(); i++)
        {
            if (candidates[i] <= target)
            {
                path.push_back(candidates[i]);
                _combinationSum(target - candidates[i], i, path, candidates);
                path.pop_back();
            }
            else
            {
                break;
            }
        }
    }

public:
    std::vector<std::vector<int>> combinationSum(std::vector<int> &candidates, int target)
    {
        std::sort(candidates.begin(), candidates.end());
        res.clear();

        std::vector<int> temp;
        _combinationSum(target, 0, temp, candidates);
        return res;
    }
};