#include <vector>
#include <string>

class Solution {
public:
    int countSubstrings(const std::string &s) 
    {
        std::vector<std::vector<int>> is_palindromic(s.size(), std::vector<int>(s.size(), 0));
        int res = s.size();

        for (int i = 0; i < is_palindromic.size(); i++)
        {
            is_palindromic[i][i] = 1;
        } 

        for (int i = 1; i < is_palindromic.size(); i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (i == j + 1)
                {
                    if (s[i] == s[j])
                    {
                        is_palindromic[i][j] = 1;
                    }
                }
                else
                {
                    if (s[i] == s[j] && is_palindromic[i - 1][j + 1])
                    {
                        is_palindromic[i][j] = 1;
                    }
                }

                res += is_palindromic[i][j];
            }
        }

        return res;
    }
};