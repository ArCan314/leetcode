#include <vector>
#include <deque>

class Solution
{
public:
    int orangesRotting(std::vector<std::vector<int>> &grid)
    {
        return orangesRottingBFS(grid);
    }

    bool rot(std::vector<std::vector<int>> &grid, int r, int c)
    {
        bool is_rot = false;
        int rsize = grid.size();
        int csize = grid.front().size();
        if (c > 0 && grid[r][c - 1] == 1)
        {
            is_rot = true;
            grid[r][c - 1] = 2;
        }
        if (c < csize - 1 && grid[r][c + 1] == 1)
        {
            is_rot = true;
            grid[r][c + 1] = 2;
        }
        if (r > 0 && grid[r - 1][c] == 1)
        {
            is_rot = true;
            grid[r - 1][c] = 2;
        }
        if (r < rsize - 1 && grid[r + 1][c] == 1)
        {
            is_rot = true;
            grid[r + 1][c] = 2;
        }
        return is_rot;
    }

    bool simulate(std::vector<std::vector<int>> &grid)
    {
        bool res = false;
        auto temp = grid;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid.front().size(); j++)
            {
                if (grid[i][j] == 2)
                {
                    bool is_rot = rot(temp, i, j);
                    res = res ? res : is_rot;
                }
            }
        grid.swap(temp);
        return res;
    }

    int orangesRottingBrutal(std::vector<std::vector<int>> &grid)
    {
        int rot_time = 0;
        while (simulate(grid))
            rot_time++;

        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid.front().size(); j++)
                if (grid[i][j] == 1)
                    return -1;

        return rot_time;
    }

    int orangesRottingBFS(std::vector<std::vector<int>> &grid)
    {
        std::deque<std::pair<int, int>> rot_pos; // <r, c>
        int fresh_count = 0;
        int rsize = grid.size();
        int csize = grid.front().size();

        for (int i = 0; i < rsize; i++)
            for (int j = 0; j < csize; j++)
                if (grid[i][j] == 1)
                    fresh_count++;
                else if (grid[i][j] == 2)
                    rot_pos.emplace_back(i, j);
        
        int rot_time = 0;
        while (rot_pos.size())
        {
            int qsize = rot_pos.size();
            while (qsize--)
            {
                const auto [r, c] = rot_pos.front();
                rot_pos.pop_front();
                if (c > 0 && grid[r][c - 1] == 1)
                {
                    grid[r][c - 1] = 2;
                    fresh_count--;
                    rot_pos.emplace_back(r, c - 1);
                }
                if (c < csize - 1 && grid[r][c + 1] == 1)
                {
                    grid[r][c + 1] = 2;
                    fresh_count--;
                    rot_pos.emplace_back(r, c + 1);
                }
                if (r > 0 && grid[r - 1][c] == 1)
                {
                    grid[r - 1][c] = 2;
                    fresh_count--;
                    rot_pos.emplace_back(r - 1, c);
                }
                if (r < rsize - 1 && grid[r + 1][c] == 1)
                {
                    grid[r + 1][c] = 2;
                    fresh_count--;
                    rot_pos.emplace_back(r + 1, c);
                }
            }
            if (rot_pos.size())
                rot_time++;
        }
        return fresh_count ? -1 : rot_time;
    }
};