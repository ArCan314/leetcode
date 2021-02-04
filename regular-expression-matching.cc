#include <string>
#include <vector>

class Solution
{
public:
    struct NFANode
    {
        char content;
        bool is_star;
    };

    std::vector<NFANode> buildNFA(const std::string &p)
    {
        std::vector<NFANode> res;
        for (int i = 0; i < p.size(); i++)
        {
            NFANode node{ p[i], false };
            if (i < p.size() - 1 && p[i + 1] == '*')
            {
                node.is_star = true;
                i++;
            }
            res.push_back(std::move(node));
        }
        return res;
    }

    bool isMatch(const std::string &s, const std::string &p)
    {
        std::vector<NFANode> nfa(std::move(buildNFA(p)));

        return isMatchRecursive(s, nfa, 0, 0);
    }

    bool isMatchRecursive(const std::string &s, const std::vector<NFANode> &nfa, int s_ptr, int nfa_ptr)
    {
        if (s_ptr == s.size() && nfa_ptr == nfa.size())
            return true;

        if ((s_ptr != s.size() && nfa_ptr == nfa.size()) || (s_ptr > s.size() || nfa_ptr > nfa.size()))
            return false;

        const auto &node = nfa[nfa_ptr];

        bool res = false;
        if (node.is_star)
        {
            res = isMatchRecursive(s, nfa, s_ptr, nfa_ptr + 1);
            if (!res)
            {
                int temp = s_ptr + 1;
                if (node.content == '.')
                {
                    while (temp <= s.size() && !res)
                        res = isMatchRecursive(s, nfa, temp++, nfa_ptr + 1);
                }
                else if (s_ptr < s.size() && node.content == s[s_ptr])
                {
                    while (temp < s.size() && s[temp] == node.content && !res)
                        res = isMatchRecursive(s, nfa, temp++, nfa_ptr + 1);
                    if (!res)
                        res = isMatchRecursive(s, nfa, temp, nfa_ptr + 1);
                }
            }
        }
        else
        {
            if (s_ptr == s.size())
                res = false;

            if (s[s_ptr] == node.content || node.content == '.')
                res = isMatchRecursive(s, nfa, s_ptr + 1, nfa_ptr + 1);
        }
        return res;
    }
};