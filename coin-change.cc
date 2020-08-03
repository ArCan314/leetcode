#include <vector>

class Solution
{
public:
    int coinChange(std::vector<int> &coins, int amount)
    {
        if (!coins.size() || amount < 0)
            return -1;
        else if (!amount)
            return 0;
        
        std::vector<int> dp(amount + 1, amount + 1);
        for (const auto coin: coins)
        {
            if (coin <= amount)
                dp[coin] = 1;
        }

        int min_coin = coins.front();

        for (int i = 1; i < amount + 1; i++)
        {
            if (dp[i] == amount + 1)
            {
                for (const auto coin: coins)
                {
                    if (i - coin > 0)
                    {
                        dp[i] = std::min(dp[i], dp[i - coin] + 1);
                    }
                }
            }
        }

        return (dp[amount] == amount + 1) ? -1 : dp[amount];
    }
};