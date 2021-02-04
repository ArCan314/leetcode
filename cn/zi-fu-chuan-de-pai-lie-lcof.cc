#include <vector>
#include <string>
#include <array>
#include <algorithm>
#include <unordered_set>
#include <bitset>

class Solution
{
public:
    std::vector<std::string> permutation(std::string s)
    {
        return permutationPermuationTree(s);
    }

    std::vector<std::string> permutationSTL(std::string s)
    {
        std::vector<std::string> res;
        std::sort(s.begin(), s.end());
        res.emplace_back(s);

        while (std::next_permutation(s.begin(), s.end()))
            res.emplace_back(s);

        return res;
    }

    std::vector<std::string> res;
    std::unordered_set<std::string> has;
    std::bitset<8> visit;
    std::string temp;

    void permutationBackTrackingImpl(const std::string &s, int cur)
    {
        if (cur == s.size())
        {
            if (has.insert(temp).second)
                res.emplace_back(temp);
            return;
        }

        for (int i = 0; i < s.size(); i++)
        {
            if (!visit[i])
            {
                visit[i] = true;
                temp.push_back(s[i]);
                permutationBackTrackingImpl(s, cur + 1);
                temp.pop_back();
                visit[i] = false;
            }
        }
    }

    std::vector<std::string> permutationBackTracking(std::string s)
    {
        res.clear();
        has.clear();
        visit.reset();
        temp.clear();
        permutationBackTrackingImpl(s, 0);
        return res;
    }

    void permutationPermuationTreeImpl(std::string &s, int cur)
    {
        if (cur == s.size())
        {
            res.emplace_back(s);
            return;
        }

        std::bitset<128> has_char;
        for (int i = cur; i < s.size(); i++)
        {
            if (has_char[s[i]])
                continue;

            has_char[s[i]] = true;
            std::swap(s[i], s[cur]);
            permutationPermuationTreeImpl(s, cur + 1);
            std::swap(s[i], s[cur]);
        }
    }

    std::vector<std::string> permutationPermuationTree(std::string s)
    {
        res.clear();
        permutationPermuationTreeImpl(s, 0);
        return res;
    }
};