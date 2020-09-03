#include <vector>

#define MAX(a, b) (((a) < (b)) ? (b) : (a)) 

class Solution
{
public:
    int integerBreak(int n)
    {
        long long dp[n + 1];

        for (int i = 0; i <= n; i++)
            dp[i] = 1;

        for (int i = 3; i <= n; i++)
            for (int j = 1; j <= i / 2; j++)
            {
                long long res = (MAX(dp[j], j) * MAX(dp[i - j], i - j)) % 1000000007;
                dp[i] = MAX(res, dp[i]);
            }
        
        return dp[n];
    }
};