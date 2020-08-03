#include <iostream>

class Solution
{
public:
    int rec_solve(int n_val, int cur_m, int n, int m, int k, int dp[], long long &res)
    {
        
    }

    int numOfArrays(int n, int m, int k)
    {
        constexpr int modulo = 1000000007;
        if (m < k)
            return 0;
        
        int dp[n + 1][m + 1];
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= m; j++)
                dp[i][j] = 0;
        
        for (int i = 1; i <= m; i++)
            dp[1][i] = 1;
        
        for (int i = 2; i <= n; i++)
            for (int j = 1; j <= m; j++)
                for (int k = 1; k <= j; k++)
                    dp[i][j] = (dp[i][j] + dp[i - 1][k]) % modulo;



        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
                std::cout << dp[i][j] << " ";
            std::cout << std::endl;
        }

        return 0;

    }
};