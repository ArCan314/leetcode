#include <vector>
#include <set>

class Solution
{
public:
    void setZerores(std::vector<std::vector<int>> &matrix)
    {
        return setZeroesInPlace(matrix);
    }

    void setZeroesSet(std::vector<std::vector<int>> &matrix)
    {
        std::set<int> zero_row_ind, zero_col_ind;
        int m = matrix.size();
        int n = matrix.front().size();
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                if (!matrix[i][j])
                {
                    zero_col_ind.insert(j);
                    zero_row_ind.insert(i);
                }
            }

        for (const auto r : zero_row_ind)
            for (int i = 0; i < n; i++)
                matrix[r][i] = 0;

        for (const auto c : zero_col_ind)
            for (int i = 0; i < m; i++)
                matrix[i][c] = 0;
    }

    void setZeroesInPlace(std::vector<std::vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix.front().size();

        bool find_zero_r = false, find_zero_c = false;
        for (int i = 0; i < m; i++)
            if (!matrix[i][0])
            {
                find_zero_r = true;
                break;
            }

        for (int i = 0; i < n; i++)
            if (!matrix[0][i])
            {
                find_zero_c = true;
                break;
            }

        for (int i = 1; i < m; i++)
            for (int j = 1; j < m; j++)
                if (!matrix[i][j])
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }

        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                if (!matrix[i][0] || !matrix[0][j])
                    matrix[i][j] = 0;
        
        if (find_zero_c)
            for (int i = 0; i < n; i++)
                matrix[0][i] = 0;
        
        if (find_zero_r)
            for (int i = 0; i < m; i++)
                matrix[i][0] = 0;
    }
};