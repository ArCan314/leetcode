#include <vector>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <iostream>

class Solution
{
private: 
    class UnionSet
    {
    public:
        UnionSet(int size)
        {
            for (int i = 0; i < size; i++)
                parent.push_back(i);
        }

        int Find(int num)
        {
            // std::cout << "Find( " << num << " )" << std::endl;
            int root = num;
            while (parent[root] != root)
                root = parent[root];

            while (parent[num] != root)
            {
                // std::cout << "\tSet num: " << num << " parent to root: " << root << std::endl;
                int num_p = parent[num];
                parent[num] = root;
                num = num_p;
            }
            // std::cout << "Find Return root: " << root << std::endl;
            return root;
        }

        void Union(int a, int b)
        {
            int root_a, root_b;
            // std::cout << "Union( " << a << " , " << b << " )" << std::endl;
            root_a = Find(a);
            root_b = Find(b);
            // std::cout << "\troot_a: " << root_a << ", " << "root_b: " << root_b << std::endl;
            if (root_a != root_b)
            {
                // std::cout << "\tSet parent[root_a] = root_b" << std::endl;
                parent[root_a] = root_b;
            }
        }
    private:
        std::vector<int> parent;
    };

public:
    int removeStones(std::vector<std::vector<int>> &stones)
    {
        return removeStonesDUS(stones);
    }

    int removeStonesDUS(std::vector<std::vector<int>> &stones)
    {
        std::unordered_map<int, std::vector<int>> col_p, row_p;
        UnionSet dus(stones.size());
        for (int i = 0; i < stones.size(); i++)
        {
            row_p[stones[i][0]].push_back(i);
            col_p[stones[i][1]].push_back(i);
        }

        for (const auto &[ind, nexts] : col_p)
            for (int i = 1; i < nexts.size(); i++)
                dus.Union(nexts[i - 1], nexts[i]);

        for (const auto &[ind, nexts] : row_p)
            for (int i = 1; i < nexts.size(); i++)
                dus.Union(nexts[i - 1], nexts[i]);
        
        // std::cout << "F" << std::endl;

        std::unordered_map<int, int> con_comp_size;

        for (int i = 0; i < stones.size(); i++)
            con_comp_size[dus.Find(i)]++;
        
        int res = 0;
        
        for (const auto [ind, size] : con_comp_size)
            res += size - 1;

        return res;
    }

    int removeStonesBFS(std::vector<std::vector<int>> &stones)
    {
        std::unordered_map<int, std::vector<int>> col_p, row_p;
        for (int i = 0; i < stones.size(); i++)
        {
            row_p[stones[i][0]].push_back(i);
            col_p[stones[i][1]].push_back(i);
        }

        std::unordered_map<int, std::unordered_set<int>> connections;

        for (int i = 0; i < stones.size(); i++)
        {
            for (const auto &row_v : row_p[stones[i][0]])
            {
                connections[i].insert(row_v);
                connections[row_v].insert(i);
            }

            for (const auto &col_v : col_p[stones[i][1]])
            {
                connections[i].insert(col_v);
                connections[col_v].insert(i);
            }
        }

        std::unordered_set<int> visited;
        std::deque<int> q;

        std::vector<std::vector<int>> con_comps;

        for (int i = 0; i < stones.size(); i++)
        {
            if (visited.insert(i).second)
                q.push_back(i);
            else
                continue;

            con_comps.emplace_back();
            while (!q.empty())
            {
                int cur = q.front();
                q.pop_front();
                con_comps.back().push_back(cur);

                for (const auto adj : connections[cur])
                    if (visited.insert(adj).second)
                        q.push_back(adj);
            }
        }

        int res = 0;

        for (int i = 0; i < con_comps.size(); i++)
            res += con_comps[i].size() - 1;

        return res;
    }
};