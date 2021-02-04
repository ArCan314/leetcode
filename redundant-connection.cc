#include <vector>
#include <unordered_map>
#include <deque>

class Solution
{
public:
    std::vector<int> findRedundantConnection(std::vector<std::vector<int>> &edges)
    {
        std::vector<int> degrees(edges.size(), 0);
        std::unordered_map<int, std::vector<int>> connections;
        for (const auto &edge : edges)
        {
            connections[edge[0] - 1].push_back(edge[1] - 1);
            connections[edge[1] - 1].push_back(edge[0] - 1);
            degrees[edge[0] - 1]++;
            degrees[edge[1] - 1]++;
        }

        std::deque<int> cut_offs;
        for (int i = 0; i < degrees.size(); i++)
            if (degrees[i] == 1)
                cut_offs.push_back(i);

        while (!cut_offs.empty())
        {
            int cur = cut_offs.front();
            cut_offs.pop_front();

            degrees[cur]--;

            for (const auto con : connections[cur])
            {
                degrees[con]--;
                if (degrees[con] == 1)
                    cut_offs.push_back(con);
            }
        }

        for (int i = edges.size() - 1; i >= 0; i--)
        {
            const auto edge = edges[i];
            int deg_a = degrees[edge[0] - 1], deg_b = degrees[edge[1] - 1];
            if ((deg_a == 2 && deg_b == 2))
                return edge;
        }
        return {};
    }
};