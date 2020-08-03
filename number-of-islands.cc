#include <vector>
#include <deque>

class Solution
{
private:
    void expand(std::vector<std::vector<char>> &grid, std::vector<std::vector<int>> &visited, int i, int j)
    {
        std::deque<std::pair<int, int>> pos_queue;
        pos_queue.push_back({i, j});
        visited[i][j] = 1;

        while (!pos_queue.empty())
        {
            auto &now_pos = pos_queue.front();
            auto &y = now_pos.first, &x = now_pos.second;
            
            // std::cout << y << ", " << x << std::endl;            
            if ((y > 0) && grid[y - 1][x] == '1' && !visited[y - 1][x])
            {
                pos_queue.push_back({y - 1, x});
                visited[y - 1][x] = 1;
            }

            if ((y < grid.size() - 1) && grid[y + 1][x] == '1' && !visited[y + 1][x])
            {
                pos_queue.push_back({y + 1, x});
                visited[y + 1][x] = 1;
            }

            if ((x > 0) && grid[y][x - 1]  == '1' && !visited[y][x - 1])
            {
                pos_queue.push_back({y, x - 1});
                visited[y][x - 1] = 1;
            }

            if ((x < grid.front().size() - 1) && grid[y][x + 1]  == '1' && !visited[y][x + 1])
            {
                pos_queue.push_back({y, x + 1});
                visited[y][x + 1] = 1;
            }

            pos_queue.pop_front();
        }
    }

public:
    int numIslands(std::vector<std::vector<char>> &grid)
    {
        if (!grid.size() || !grid.front().size())
            return 0;

        std::vector<std::vector<int>> visited(grid.size(), std::vector<int>(grid.front().size(), 0));
        int island_num = 0;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid.front().size(); j++)
            {
                if (grid[i][j]  == '0' || (grid[i][j]  == '1' && visited[i][j]))
                {
                    continue;
                }
                else
                {
                    // std::cout << i << ",a " << j << std::endl;
                    island_num++;
                    expand(grid, visited, i, j);
                }
            }
        }

        return island_num;
    }
};