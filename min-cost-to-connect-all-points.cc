#include <vector>
#include <unordered_set>
#include <map>
#include <queue>
#include <algorithm>

class Solution
{
public:
    const int getDist(const std::vector<int> &pa, const std::vector<int> &pb) const
    {
        return std::abs(pa[0] - pb[0]) + std::abs(pa[1] - pb[1]);
    }

    int minCostConnectPoints(std::vector<std::vector<int>> &points)
    {
        return minCostConnectPointsKruscal(points);
    }

    class DisjointUnionSet
    {
    public:
        DisjointUnionSet(int size) : rank(size, 1) 
        {
            for (int i = 0; i < size; i++)
                parent.push_back(i);
        }

        int Find(int num)
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

        void Union(int a, int b)
        {
            int root_a = Find(a), root_b = Find(b);
            if (root_a != root_b)
            {
                if (rank[root_a] > rank[root_b])
                    std::swap(root_a, root_b);
                rank[root_b] += rank[root_a];
                parent[root_a] = root_b;
            }
        }
    private:
        std::vector<int> parent;
        std::vector<int> rank;
    };

    int minCostConnectPointsKruscal(std::vector<std::vector<int>> &points)
    {
        std::priority_queue<
            std::tuple<int, int, int>, 
            std::vector<std::tuple<int, int, int>>, 
            std::greater<std::tuple<int, int, int>>> min_heap;
        for (int i = 0; i < points.size() - 1; i++)
            for (int j = i + 1; j < points.size(); j++)
                min_heap.push({getDist(points[i], points[j]), i, j});
        
        DisjointUnionSet dus(points.size());
        int count = 0;
        int cost = 0;

        while (count != points.size() - 1)
        {
            const auto [cur_cost, start, end] = min_heap.top();
            int parent_start = dus.Find(start), parent_end = dus.Find(end);

            if (parent_end != parent_start)
            {
                dus.Union(parent_start, parent_end);
                count++;
                cost += cur_cost;
            }
            min_heap.pop();
        }

        return cost;
    }

    int minCostConnectPointsPrim(std::vector<std::vector<int>> &points)
    {
        std::unordered_set<int> vset_a, vset_b;
        vset_a.insert(0);
        for (int i = 1; i < points.size(); i++)
            vset_b.insert(i);

        int cost = 0;

        std::vector<int> min_costs(points.size(), -1);
        for (int i = 1; i < points.size(); i++)
            min_costs[i] = getDist(points[0], points[i]);

        while (vset_a.size() != points.size())
        {
            int cur_min_cost = min_costs[*(vset_b.begin())];
            int cur_min_ind = *(vset_b.begin());
            for (const auto ind : vset_b)
                if (min_costs[ind] < cur_min_cost)
                {
                    cur_min_cost = min_costs[ind];
                    cur_min_ind = ind;
                }

            for (const auto ind : vset_b)
                min_costs[ind] = std::min(min_costs[ind], getDist(points[cur_min_ind], points[ind]));

            cost += cur_min_cost;
            vset_a.insert(cur_min_ind);
            vset_b.erase(cur_min_ind);
        }

        return cost;
    }
};