#include <vector>
#include <algorithm>
#include <deque>
#include <bitset>

class Solution
{
private:
    static bool isBetweenEqual(const int val, const int lo, const int hi) noexcept
    {
        return lo <= val && val <= hi;
    }

public:
    int minimumEffortPath(const std::vector<std::vector<int>> &heights)
    {
        return MinimumEffortPathBfsBs().solve(heights);
    }

    class MinimumEffortPathBfsBs
    {
    public:
        int m{}, n{};
        std::bitset<10000> visit;

        int solve(const std::vector<std::vector<int>> &hegihts)
        {
            m = hegihts.size();
            n = hegihts[0].size();
            int lo = 0, hi = 1000001;
            while (lo < hi)
            {
                int mid = lo + (hi - lo) / 2;
                // cout << lo << ", " << mid << ", " << hi << endl;
                bool has_reach = bfs(hegihts, mid);
                if (has_reach)
                    hi = mid;
                else
                    lo = mid + 1;
            }
            return lo;
        }

        bool bfs(const std::vector<std::vector<int>> &heights, int max_cost)
        {
            visit.reset();
            std::deque<int> expand;
            
            visit[0] = true;
            expand.emplace_back(0);
            
            while (expand.size())
            {
                int x = expand.front() % n, y = expand.front() / n;
                expand.pop_front();

                if (x == n - 1 && y == m - 1)
                    return true;
                
                static int dy[] = {-1, 1, 0, 0};
                static int dx[] = {0, 0, -1, 1};

                for (int i = 0; i < sizeof(dy) / sizeof(decltype(dy[0])); i++)
                {
                    int new_x = x + dx[i], new_y = y + dy[i];
                    if (isBetweenEqual(new_x, 0, n - 1) && isBetweenEqual(new_y, 0, m - 1) && !visit[new_x + new_y * n])
                    {
                        int effort = std::abs(heights[new_y][new_x] - heights[y][x]);
                        if (effort <= max_cost)
                        {
                            visit[new_x + new_y * n] = true;
                            expand.push_back(new_x + new_y * n);
                        }
                    }
                }
            }
            return false;
        }
    };

    class MinimumEffortPathDfs
    {
    private:
        int m{}, n{};
        int res{};

    public:
        int solve(const std::vector<std::vector<int>> &heights)
        {
            res = 0x7fffffff;

            m = heights.size();
            n = heights[0].size();

            std::vector<std::vector<int>> visit(heights.size(), std::vector<int>(heights[0].size(), 0));
            visit[0][0] = 1;

            solveImpl(heights, visit, 0, 0, 0);
            return res;
        }

        void solveImpl(
            const std::vector<std::vector<int>> &hegihts,
            std::vector<std::vector<int>> &visit,
            int x, int y,
            int effort)
        {
            if (y == m - 1 && x == n - 1)
            {
                res = effort;
                return;
            }

            if (effort >= res)
                return;

            static int dy[] = {-1, 1, 0, 0};
            static int dx[] = {0, 0, -1, 1};

            for (int i = 0; i < 4; i++)
            {
                int new_x = x + dx[i], new_y = y + dy[i];
                if (isBetweenEqual(new_x, 0, n - 1) && isBetweenEqual(new_y, 0, m - 1) && !visit[new_y][new_x])
                {
                    visit[new_y][new_x] = 1;
                    solveImpl(hegihts, visit, new_x, new_y, std::max(effort, std::abs(hegihts[y][x] - hegihts[new_y][new_x])));
                    visit[new_y][new_x] = 0;
                }
            }
        }
    };

    
};