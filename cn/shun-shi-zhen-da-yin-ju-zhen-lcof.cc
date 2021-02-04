#include <vector>

class Solution
{
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>> &matrix)
    {
        if (!matrix.size() || !matrix[0].size())
            return {};

        int m = matrix.size();
        int n = matrix[0].size();
        int top, bottom, left, right;
        int count = 0;
        std::vector<int> res(m * n, 0);

        top = 0;
        bottom = m - 1;
        left = 0;
        right = n - 1;

        int x = 0, y = 0, dir = 0;
        int dx[] = {1, 0, -1, 0}; // L->R, T->B, R->L, B->T
        int dy[] = {0, 1, 0, -1}; // L->R, T->B, R->L, B->T

        while (count < m * n)
        {
            res[count++] = matrix[y][x];

            if (dir == 0 && x == right)
            {
                dir = 1;
                top++;
            }
            else if (dir == 1 && y == bottom)
            {
                dir = 2;
                right--;
            }
            else if (dir == 2 && x == left)
            {
                dir = 3;
                bottom--;
            }
            else if (dir == 3 && y == top)
            {
                dir = 0;
                left++;
            }

            x += dx[dir];
            y += dy[dir];
        }
        return res;
    }
};