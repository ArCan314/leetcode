#include <string>
#include <vector>

#define MAX(a, b) ((a) < (b) ? (b) : (a))

class Solution
{
public:
    int longestCommonSubsequence(const std::string &text1, const std::string &text2)
    {
        if (!text1.size() || !text2.size())
            return 0;
        // std::vector<std::vector<int>> dp(text1.size() + 1, std::vector<int>(text2.size() + 1, 0));
        int s1 = text1.size(), s2 = text2.size();
        int dp[s1 + 1][s2 + 1];
        for (int i = 0; i <= s1; i++)
            dp[i][0] = 0;
        for (int i = 0; i <= s2; i++)
            dp[0][i] = 0;

        for (int i = 1; i <= s1; i++)
            for (int j = 1; j <= s2; j++)
            {
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = MAX(dp[i - 1][j], dp[i][j - 1]);
            }
        
        return dp[s1][s2];
    }
};