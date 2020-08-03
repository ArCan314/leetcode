#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

class Solution
{
public:
    std::string longestPalindromeDP(std::string &s)
    {
        std::vector<std::vector<int>> dp(s.size(), std::vector<int>(s.size(), 0));
        int l = 0, r = 0;

        for (int i = 0; i < s.size(); i++)
        {
            dp[i][i] = 1;
        }

        for (int i = 1; i < s.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (i == j + 1)
                {
                    if (s[i] == s[j])
                    {
                        dp[i][j] = 1;
                        if (i - j > r - l)
                        {
                            l = j;
                            r = i;
                        }
                    }
                }
                else
                {
                    if (s[i] == s[j] && dp[i - 1][j + 1])
                    {
                        dp[i][j] = 1;
                        if (i - j > r - l)
                        {
                            r = i;
                            l = j;
                        }
                    }
                }
            }
        }

        return s.substr(l, r - l + 1);
    }

    std::string longestPalindrome(std::string &s) const // expand
    {
        int l = 0, r = 0, len = 1;

        for (int i = 0; i < s.size(); i++)
        {
            int len_odd = expand(s, i, i);
            int len_even = expand(s, i, i + 1);

            if (len < std::max(len_odd, len_even))
            {
                if (len_odd > len_even)
                {
                    l = i - (len_odd - 1) / 2;
                    r = i + (len_odd - 1) / 2;
                    len = len_odd;
                }
                else
                {
                    l = i - (len_even - 2) / 2;
                    r = i + (len_even - 2) / 2 + 1;
                    len = len_even;
                }
            }
        }

        return s.substr(l, r - l + 1);
    }

    int expand(const std::string &s, int l, int r) const
    {
        while (l >= 0 && r < s.size() && s[l] == s[r])
        {
            l--, r++;
        }
        return r - l + 1;
    }
};