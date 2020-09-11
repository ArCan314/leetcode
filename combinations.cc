#include <vector>

class Solution
{
public:
    void _combine(std::vector<std::vector<int>> &results, std::vector<int> &result, int n, int k, int cur)
    {
        if (!k)
        {
            results.push_back(result);
            return;
        }

        if (n - cur + 1 < k)
            return;

        for (int i = cur; i <= n; i++)
        {
            result.push_back(i);
            _combine(results, result, n, k - 1, i + 1);
            result.pop_back();
        }
    }

    std::vector<std::vector<int>> combine(int n, int k)
    {
        std::vector<std::vector<int>> result;
        std::vector<int> temp;
        _combine(result, temp, n, k, 1);
        return result;
    }
};