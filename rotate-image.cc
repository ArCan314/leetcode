#include <vector>
#include <algorithm>

class Solution
{
public:
    void rotate(std::vector<std::vector<int>> &matrix)
    {
        for (int i = 0; i < matrix.size() / 2; i++)
        {
            int a = matrix.size() - 1 - i;
            for (int j = i; j < matrix.size() - i - 1; j++)
            {
                int b = matrix.size() - 1 - j;
                // int &a = matrix[i][j];
                // int &b = matrix[j][matrix.size() - 1 - i];
                // int &c = matrix[matrix.size() - i - 1][matrix.size() - 1 - j];
                // int &d = matrix[matrix.size() - 1 - j][i];

                std::swap(matrix[i][j], matrix[b][i]);
                std::swap(matrix[j][a], matrix[a][b]);
                std::swap(matrix[j][a], matrix[b][i]);
            }
        }
    }
};