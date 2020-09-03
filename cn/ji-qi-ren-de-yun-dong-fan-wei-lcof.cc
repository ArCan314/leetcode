#include <vector>
#include <deque>
#include <array>

class Solution
{
public:
    int movingCount(int m, int n, int k)
    {
        std::array<int, 100> lut;

        for (int i = 0; i < lut.size(); i++)
            lut[i] = i / 10 + i % 10;

        std::vector<std::vector<int>> visited(m, std::vector<int>(n, 0));
        std::deque<std::pair<int, int>> q;

        q.emplace_back(0, 0);
        visited[0][0] = 1;

        int res = 0;

        while (!q.empty())
        {
            auto [row, col] = q.front();
            q.pop_front();
            res++;

            if (col > 1 && lut[row] + lut[col - 1] <= k && !visited[row][col - 1])
            {
                visited[row][col - 1] = 1;
                q.emplace_back(row, col - 1);
            }

            if (col < n - 1 && lut[row] + lut[col + 1] <= k && !visited[row][col + 1])
            {
                visited[row][col + 1] = 1;
                q.emplace_back(row, col + 1);
            }

            if (row > 1 && lut[row - 1] + lut[col] <= k && !visited[row - 1][col])
            {
                visited[row - 1][col] = 1;
                q.emplace_back(row - 1, col);
            }

            if (row < m - 1 && lut[row + 1] + lut[col] <= k && !visited[row + 1][col])
            {
                visited[row + 1][col] = 1;
                q.emplace_back(row + 1, col);
            }
        }

        return res;
    }
};