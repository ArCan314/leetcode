class Solution {
public:
    int countNumbersWithUniqueDigits(int n) 
    {
        int dp[15]{};
        dp[0] = 1;
        dp[1] = 9;
        
        for (int i = 2; i <= 11; i++)
            dp[i] = dp[i - 1] * (11 - i);
        
        for (int i = 1; i <= 11; i++)
            dp[i] = dp[i] + dp[i - 1];
        
        return (n >= 11) ? dp[11] : dp[n];
    }
};