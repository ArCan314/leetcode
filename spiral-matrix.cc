#include <vector>

class Solution
{
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>> &matrix)
    {
        std::vector<int> res;
        std::pair<int, int> dx[] = {
            {0, -1}, // u
            {0, 1},  // d
            {-1, 0}, // l
            {1, 0},  // r
        };
        int m = matrix.size(), n = matrix.front().size();
        res.reserve(m * n);
        int l = 0, b = m, t = 0, r = n;
        int pos[2]{0, 0};
        enum State
        {
            UP,
            DOWN,
            LEFT,
            RIGHT
        } state = RIGHT;

        int count = 0;
        while (count < m * n)
        {
            res.push_back(matrix[pos[1]][pos[0]]);
            count++;
            switch (state)
            {
            case UP:
                if (pos[1] == t)
                {
                    pos[0]++;
                    t++;
                    state = RIGHT;
                }
                else
                {
                    pos[1]--;
                }
                break;
            case DOWN:
                if (pos[1] == b - 1)
                {
                    pos[0]--;
                    b--;
                    state = LEFT;
                } 
                else
                {
                    pos[1]++;
                }
                break;
            case RIGHT:
                if (pos[0] == r - 1)
                {
                    pos[1]++;
                    r--;
                    state = DOWN;
                }
                else
                {
                    pos[0]++;
                }
                break;
            case LEFT:
                if (pos[0] == 0)
                {
                    pos[1]--;
                    l++;
                    state = UP;
                }
                else
                {
                    pos[0]--;
                }
                break;
            default:
                break;
            }
        }
        return res;
    }
};