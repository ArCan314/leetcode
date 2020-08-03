#include <vector>

class Solution
{
public:
    std::vector<std::vector<int>> generate(int numRows)
    {
        std::vector<std::vector<int>> res(numRows, std::vector<int>());
        for (int i = 0; i < res.size(); i++)
        {
            res[i].resize(i + 1);
        }

        for (int i = 0; i < res.size(); i++)
        {
            for (int j = 0; j < res[i].size(); j++)
            {
                if (j == 0 || j == res[i].size() - 1)
                {
                    res[i][j] = 1;
                }
                else
                {
                    res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
                }
            }
        }

        return res;
    }
};