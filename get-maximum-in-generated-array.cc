#include <algorithm>

class Solution
{
public:
    int getMaximumGenerated(int n)
    {
        return getMaximumGeneratedDP(n);
    }
    int getMaximumGeneratedDP(int n)
    {
        int dp[101];
        dp[0] = 0;
        dp[1] = 1;
        int res = n ? 1 : 0;
        for (int i = 2; i <= n; i++)
        {
            if (i % 2)
                dp[i] = dp[i / 2] + dp[i / 2 + 1];
            else
                dp[i] = dp[i / 2];
            res = std::max(res, dp[i]);
        }

        return res;
    }
};