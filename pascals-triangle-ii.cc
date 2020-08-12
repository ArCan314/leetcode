#include <vector>
#include <cmath>


class Solution
{
public:
    std::vector<int> getRow(int rowIndex)
    {
        std::vector<int> res(rowIndex + 1, 1);
        for (int i = 1; i < res.size(); i++)
            res[i] = res[i - 1] / static_cast<double>(i) * (rowIndex - i + 1);
        return res;
    }
};