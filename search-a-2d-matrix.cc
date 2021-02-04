#include <vector>

class Solution
{
public:
    bool searchMatrix(std::vector<std::vector<int>> &matrix, int target)
    {
        return searchMatrixBinarySearch(matrix, target);
    }

    bool searchMatrixBinarySearch(std::vector<std::vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        int l = 0, r = m;
        while (l < r - 1)
        {
            int mid = l + (r - l) / 2;
            if (matrix[mid][0] < target)
                l = mid;
            else if (matrix[mid][0] > target)
                r = mid;
            else
                l = r = mid;
        }

        int row = l;
        l = 0, r = n - 1;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (matrix[row][mid] < target)
                l = mid + 1;
            else if (matrix[row][mid] > target)
                r = mid - 1;
            else
                l = r = mid;
        }
        return matrix[row][l] == target;
    }

    bool searchMatrixLinear(std::vector<std::vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        int r = m - 1;
        for (int i = 0; i < m - 1; i++)
            if (matrix[i][0] <= target && matrix[i + 1][0] > target)
            {
                r = i;
                break;
            }

        bool res = false;
        for (int i = 0; i < n && !res; i++)
            if (matrix[r][i] == target)
                res = true;
            else if (matrix[r][i] > target)
                break;
        return res;
    }
};