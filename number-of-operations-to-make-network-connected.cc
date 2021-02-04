#include <vector>

class Solution {
public:
    class DisjointUnionSet
    {
    public:
        DisjointUnionSet(int size) : con_count(size)
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
                parent[root_a] = root_b;
                con_count--;
            }
        }

        int getCon() const { return con_count; }
    private:
        std::vector<int> parent;
        int con_count;
    };

    int makeConnected(int n, vector<vector<int>>& connections) 
    {
        if (connections.size() + 1 < n)
            return -1;
        
        DisjointUnionSet dju(n);
        for (const auto &connection : connections)
            dju.Union(connection[0], connection[1]);

        return dju.getCon() - 1;
    }
};