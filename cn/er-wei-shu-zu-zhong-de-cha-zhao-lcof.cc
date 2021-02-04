#include <vector>

class Solution
{
public:
    bool findNumberIn2DArray(std::vector<std::vector<int>> &matrix, int target)
    {
        if (!matrix.size() || !matrix[0].size())
            return false;

        int m = matrix.size();
        int n = matrix[0].size();

        int r = 0;
        int c = n - 1;

        while (r < m && c >= 0)
        {
            if (matrix[r][c] > target)
                c--;
            else if (matrix[r][c] < target)
                r++;
            else
                return true;
        }

        return false;
    }
};