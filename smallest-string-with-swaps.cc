#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <algorithm>

class Solution
{
public:
    std::string smallestStringWithSwaps(std::string s, const std::vector<std::vector<int>> &pairs)
    {
        return smallestStringWithSwapsUnionFind(s, pairs);
    }

    std::string smallestStringWithSwapsBFS(std::string &s, const std::vector<std::vector<int>> &pairs)
    {
        std::unordered_map<int, std::unordered_set<int>> graph;
        
        for (const auto &pair : pairs)
        {
            graph[pair[0]].insert(pair[1]);
            graph[pair[1]].insert(pair[0]);
        }

        std::vector<std::vector<int>> con_comps;
        std::unordered_set<int> visit;
        std::deque<int> q;

        for (const auto &[ind, nexts] : graph)
        {
            if (!visit.count(ind))
                visit.insert(ind);
            
            q.push_back(ind);
            con_comps.emplace_back();

            while (!q.empty())
            {
                int cur_ind = q.front();
                q.pop_front();

                con_comps.back().push_back(cur_ind);

                for (const auto next : graph[cur_ind])
                    if (!visit.count(next))
                    {
                        q.push_back(next);
                        visit.insert(next);
                    }
            }
        }

        for (auto &con_comp : con_comps)
            std::sort(con_comp.begin(), con_comp.end());

        std::string temp;
        for (const auto &con_comp : con_comps)
        {
            temp.clear();
            for (const auto con_ind : con_comp)
                temp.push_back(s[con_ind]);

            std::sort(temp.begin(), temp.end());
            
            for (int i = 0; i < temp.size(); i++)
                s[con_comp[i]] = temp[i];
        }
        return s;
    }

    std::string smallestStringWithSwapsUnionFind(std::string &s, const std::vector<std::vector<int>> &pairs)
    {
        class UnionFind
        {
        private:
            std::unordered_map<int, int> parent;
        public:
            void add(int num)
            {
                if (auto iter = parent.find(num); iter == parent.end())
                    parent.insert(iter, {num, -1});
            }

            void merge(int a, int b)
            {
                int root_a = find(a);
                int root_b = find(b);

                if (root_a != root_b)
                {
                    // cout << "merge: root_a = " << root_a << ", root_b = " << root_b << endl;
                    parent.at(root_a) = root_b;
                }
            }

            int find(int num)
            {
                int root = num;
                
                while (parent.at(root) != -1)
                    root = parent.at(root);
                // cout << "find " << num << ", root = " << root << endl;
                while (num != root)
                {
                    int num_parent = parent.at(num);
                    parent.at(num) = root;
                    // cout << "update num = " << num << ", root = " << root << endl;
                    num = num_parent;
                }
                
                return root;
            }

            bool is_connected(int a, int b)
            {
                return find(a) == find(b);
            }
        };

        UnionFind union_find;

        for (const auto &pair : pairs)
        {
            union_find.add(pair[0]);
            union_find.add(pair[1]);
            union_find.merge(pair[0], pair[1]);
        }

        std::unordered_map<int, std::vector<int>> con_comps;
        std::unordered_set<int> visit;

        for (const auto &pair : pairs)
            for (const auto num : pair)
                if (visit.insert(num).second)
                    con_comps[union_find.find(num)].push_back(num);

        std::string temp;
        for (auto &[root, con_comp] : con_comps)
        {
            temp.clear();

            std::sort(con_comp.begin(), con_comp.end());


            for (const auto ind : con_comp)
            {
                // cout << ind << ", ";
                temp.push_back(s[ind]);
            }
            // cout << endl;

            std::sort(temp.begin(), temp.end());

            for (int i = 0; i < temp.size(); i++)
                s[con_comp[i]] = temp[i];
        }

        return s;
    }
};