#include <vector>

class Solution
{
public:
    void _combinationSum3(std::vector<std::vector<int>> &results, std::vector<int> &result, int cur_num, int k, int n)
    {
        if (!k)
        {
            if (!n)
                results.push_back(result);
            return;
        }

        for (int i = cur_num; i <= 9; i++)
        {
            if (n - i >= 0)
            {
                result.push_back(i);
                _combinationSum3(results, result, i + 1, k - 1, n - i);
                result.pop_back();
            }
            else
                break;
        }
    }

    std::vector<std::vector<int>> combinationSum3(int k, int n)
    {
        std::vector<std::vector<int>> res;
        std::vector<int> temp;
        _combinationSum3(res, temp, 1, k, n);
        return res;
    }
};