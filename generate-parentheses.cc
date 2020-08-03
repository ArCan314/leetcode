#include <vector>
#include <string>

class Solution
{
private:
    void _generateParenthesis(int n, int now, int has, std::string &s)
    {
        if (now == n)
        {
            res.push_back(s);
            while (has--)
            {
                res.back().push_back(')');
            }
        }
        else
        {
            s.push_back('(');
            _generateParenthesis(n, now + 1, has + 1, s);
            s.pop_back();

            if (has)
            {
                s.push_back(')');
                _generateParenthesis(n, now, has - 1, s);
                s.pop_back();
            }
        }
    }

    std::vector<std::string> res;
public:
    std::vector<std::string> generateParenthesis(int n)
    {
        res.clear();
        std::string temp;
        _generateParenthesis(n, 0, 0, temp);
        return res;
    }
};