#include <vector>
#include <string>
#include <map>

class Solution
{
public:
    bool DFSFind(const std::vector<std::vector<std::pair<double, int>>> &graph,
                 std::vector<int> &visit,
                 const int now, const int target, double &res)
    {
        if (now == target)
            return true;

        for (const auto &[weight, next] : graph[now])
        {
            if (visit[next])
                continue;

            double res_temp = res;
            res *= weight;
            visit[next] = 1;
            bool is_find = DFSFind(graph, visit, next, target, res);
            visit[next] = 0;
            if (is_find)
                return true;
            res = res_temp;
        }

        return false;
    }

    std::vector<double> calcEquation(std::vector<std::vector<std::string>> &equations,
                                     std::vector<double> &values,
                                     std::vector<std::vector<std::string>> &queries)
    {
        std::map<std::string, int> str_to_ind;
        std::vector<std::vector<std::pair<double, int>>> graph;

        for (int i = 0; i < equations.size(); i++)
        {
            for (const auto &s : equations[i])
            {
                if (!str_to_ind.count(s))
                {
                    str_to_ind[s] = graph.size();
                    graph.emplace_back();
                }
            }

            const std::string &a = equations[i][0], &b = equations[i][1];
            int ind_a = str_to_ind.at(a), ind_b = str_to_ind.at(b);
            graph[ind_a].emplace_back(values[i], ind_b);
            graph[ind_b].emplace_back(1.0 / values[i], ind_a);
        }

        std::vector<double> res;
        std::vector<int> visit(graph.size(), 0);
        for (const auto &query : queries)
        {
            const std::string &from = query[0], &to = query[1];
            if (!str_to_ind.count(from) || !str_to_ind.count(to))
            {
                res.push_back(-1.0);
                continue;
            }

            double calc_res = 1.0;
            int ind_from = str_to_ind[from], ind_to = str_to_ind[to];

            if (ind_from == ind_to)
            {
                res.push_back(1.0);
                continue;
            }

            visit[ind_from] = 1;
            if (!DFSFind(graph, visit, ind_from, ind_to, calc_res))
                res.push_back(-1.0);
            else
                res.push_back(calc_res);
            visit[ind_from] = 0;
        }

        return res;
    }
};