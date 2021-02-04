#include <vector>
#include <bitset>
#include <deque>
#include <numeric>
#include <queue>

class Solution
{
public:
    int swimInWater(std::vector<std::vector<int>> &grid)
    {
        return swimInWaterDju(grid);
    }

    bool BfsImpl(const std::vector<std::vector<int>> &grid, int height)
    {
        static std::bitset<2500> visit;
        visit.reset();
        int size = grid.size();

        if (grid[0][0] > height)
            return false;

        std::deque<int> expand;

        expand.emplace_back(0);
        visit[0] = true;

        static constexpr int dx[] = {0, 0, -1, 1}; // T, B, L, R
        static constexpr int dy[] = {-1, 1, 0, 0};

        while (!expand.empty())
        {
            int y = expand.front() / size, x = expand.front() % size;
            expand.pop_front();

            if (y == size - 1 && x == size - 1)
                return true;

            for (int i = 0; i < sizeof(dx) / sizeof(decltype(dx[0])); i++)
            {
                int new_y = y + dy[i], new_x = x + dx[i];
                if (new_y < 0 || new_y >= size || new_x < 0 || new_x >= size)
                    continue;

                if (grid[new_y][new_x] <= height && !visit[new_y * size + new_x])
                {
                    expand.emplace_back(new_y * size + new_x);
                    visit[new_y * size + new_x] = true;
                }
            }
        }

        return false;
    }

    int swimInWaterBfsWithBinarySearch(const std::vector<std::vector<int>> &grid)
    {
        int n = grid.size();
        int lo = 0, hi = n * n - 1;

        while (lo < hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (BfsImpl(grid, mid))
                hi = mid;
            else
                lo = mid + 1;
        }

        return lo;
    }

    bool DfsImpl(const std::vector<std::vector<int>> &grid, int height, int cur_x, int cur_y, std::bitset<2500> &visit)
    {
        if (cur_x == grid.size() - 1 && cur_y == grid.size() - 1)
            return true;

        static constexpr int dx[] = {0, 0, -1, 1}; // T, B, L, R
        static constexpr int dy[] = {-1, 1, 0, 0};
        bool res = false;

        for (int i = 0; i < sizeof(dx) / sizeof(decltype(dx[0])) && !res; i++)
        {
            int new_x = cur_x + dx[i], new_y = cur_y + dy[i];
            if (new_x < 0 || new_x >= grid.size() || new_y < 0 || new_y >= grid.size())
                continue;

            if (grid[new_y][new_x] <= height && !visit[new_y * grid.size() + new_x])
            {
                visit[new_y * grid.size() + new_x] = true;
                res = DfsImpl(grid, height, new_x, new_y, visit);
                visit[new_y * grid.size() + new_x] = false;
            }
        }

        return res;
    }

    int swimInWaterDfsWithBinarySearch(const std::vector<std::vector<int>> &grid) // TLE
    {
        int n = grid.size();
        int lo = 0, hi = n * n - 1;
        std::bitset<2500> visit;
        visit[0] = true;

        while (lo < hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (grid[0][0] <= mid && DfsImpl(grid, mid, 0, 0, visit))
                hi = mid;
            else
                lo = mid + 1;
        }

        return lo;
    }

    class DisjointUnionSet
    {
    private:
        std::vector<int> parent;
        std::vector<int> rank;
    public:
        DisjointUnionSet(int size) : parent(size, 0), rank(size, 1) 
        {
            std::iota(parent.begin(), parent.end(), 0);
        }

        int find(int num)
        {
            int root = num;
            while (parent[root] != root)
                root = parent[root];
            
            while (num != root)
            {
                int num_parent = parent[num];
                parent[num] = root;
                num = num_parent;
            }

            return root;
        }

        void merge(int a, int b)
        {
            int root_a = find(a), root_b = find(b);
            if (root_a != root_b)
            {
                if (rank[root_a] > rank[root_b])
                    std::swap(root_a, root_b);

                parent[root_a] = root_b;
                rank[root_b] += rank[root_a];
            }
        }
    };

    int swimInWaterDju(const std::vector<std::vector<int>> &grid)
    {
        int size = grid.size();
        DisjointUnionSet dju(size * size);

        using Edge = std::tuple<int, int, int>;
        std::priority_queue<Edge, std::vector<Edge>, std::greater<Edge>> pq;

        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
            {
                if (i < size - 1)
                {
                    int val = std::max(grid[i + 1][j], grid[i][j]);
                    int from = (grid[i + 1][j] > grid[i][j]) ? (i * size + j) : ((i + 1) * size + j);
                    int to = (grid[i + 1][j] > grid[i][j]) ? ((i + 1) * size + j) : (i * size + j);
                    pq.emplace(val, from, to);
                }
                if (j < size - 1)
                {
                    int val = std::max(grid[i][j], grid[i][j + 1]);
                    int from = (grid[i][j + 1] > grid[i][j]) ? (i * size + j) : (i * size + j + 1);
                    int to = (grid[i][j + 1] > grid[i][j]) ? (i * size + j + 1) : (i * size + j);
                    pq.emplace(val, from, to);
                }
            }
        
        int res = 0;
        while (!pq.empty())
        {
            const auto [val, from, to] = pq.top();
            pq.pop();

            res = val;
            dju.merge(from, to);
            if (dju.find(0) == dju.find(size * size - 1))
                return res;
        }
        return 0;
    }
};