#include <algorithm>

class Solution {
public:
    int numSquares(int n) 
    {
        int *dp = new int[n + 1]();
        int res;
        dp[1] = 1;
        
        for (int i = 2; i * i <= n; i++)
            dp[i * i] = 1;
        
        for (int i = 2; i <= n; i++)
        {
            if (dp[i] != 1)
            {   
                int temp = 0x7fffffff;
                for (int j = 1; j * j < i; j++)
                {
                    temp = std::min(temp, dp[i - j * j] + 1);
                }
                dp[i] = temp;
            }
        }
        
        res = dp[n];
        delete[] dp;
        
        return res;
    }
};