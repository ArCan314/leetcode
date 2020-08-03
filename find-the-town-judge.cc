#include <vector>

class Solution
{
public:
    int findJudge(int N, std::vector<std::vector<int>> &trust)
    {
        std::vector<std::pair<int, int>> vertices(N + 1);

        for (const auto &from_to : trust)
        {
            vertices[from_to[0]].first++;
            vertices[from_to[1]].second++;
        }

        int res = -1;
        for (int i = 1; i <= N; i++)
            if (!vertices[i].first && vertices[i].second == (N - 1))
            {
                res = i;
                break;
            }
        return res;
    }
};