#include <vector>

class Solution
{
public:
    bool searchMatrix(std::vector<std::vector<int>> &matrix, int target)
    {
        return searchMatrixLinear(matrix, target);
    }

    bool searchMatrixBruteForce(std::vector<std::vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (matrix[i][j] == target)
                    return true;
        return false;
    }

    bool searchMatrixRowBFColBS(std::vector<std::vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        bool res = false;
        for (int i = 0; i < m; i++)
        {
            if (matrix[i][0] <= target && matrix[i][n - 1] >= target)
            {
                int l = 0, r = n - 1;
                while (l < r)
                {
                    int mid = l + (r - l) / 2;
                    if (matrix[i][mid] > target)
                        r = mid - 1;
                    else if (matrix[i][mid] < target)
                        l = mid + 1;
                    else
                        l = r = mid;
                }
                if (matrix[i][l] == target)
                {
                    res = true;
                    break;
                }
            }
            else if (matrix[i][0] > target)
                break;
        }

        return res;
    }

    bool searchMatrixRowBFColBSOptimize(std::vector<std::vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        bool res = false;

        if (m <= n)
        {
            for (int i = 0; i < m; i++)
            {
                if (matrix[i][0] <= target && matrix[i][n - 1] >= target)
                {
                    int l = 0, r = n - 1;
                    while (l < r)
                    {
                        int mid = l + (r - l) / 2;
                        if (matrix[i][mid] > target)
                            r = mid - 1;
                        else if (matrix[i][mid] < target)
                            l = mid + 1;
                        else
                            l = r = mid;
                    }
                    if (matrix[i][l] == target)
                    {
                        res = true;
                        break;
                    }
                }
                else if (matrix[i][0] > target)
                    break;
            }
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                if (matrix[0][i] <= target && matrix[m - 1][i] >= target)
                {
                    int l = 0, r = m - 1;
                    while (l < r)
                    {
                        int mid = l + (r - l) / 2;
                        if (matrix[mid][i] > target)
                            r = mid - 1;
                        else if (matrix[mid][i] < target)
                            l = mid + 1;
                        else
                            l = r = mid;
                    }
                    if (matrix[l][i] == target)
                    {
                        res = true;
                        break;
                    }
                }
                else if (matrix[0][i] > target)
                    break;
            }
        }

        return res;
    }

    bool searchMatrixLinear(std::vector<std::vector<int>> &matrix, int target)
    {
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