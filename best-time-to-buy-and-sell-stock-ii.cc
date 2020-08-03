#include <vector>
#include <algorithm>
#include <utility>

class Solution
{
public:
    int maxProfitDP(const std::vector<int> &prices)
    {
        if (prices.size() < 2)
            return 0;

        std::vector<std::vector<int>> dp(prices.size(), std::vector<int>(prices.size(), 0));

        for (int step = 1; step < prices.size(); step++)
        {
            for (int i = 0; i < prices.size(); i++) // dp[0][i] to dp[i+1][i+step]
            {
                int j = std::min(static_cast<unsigned long>(i + step), prices.size() - 1);
                
                int cur_max = 0;
                for (int k = i; k < j; k++)
                {
                    cur_max = std::max(cur_max, dp[i][k] + dp[k + 1][j]);
                }
                cur_max = std::max(cur_max, prices[j] - prices[i]);
                dp[i][j] = cur_max;
            }
        }
        return dp[0][prices.size() - 1];
    }

    int maxProfit(const std::vector<int> &prices)
    {
        if (prices.size() < 2)
            return 0;

        int i = 0;
        int p, v;
        p = v = prices.front();
        int res = 0;

        while (i < prices.size() - 1)
        {
            while (i < prices.size() - 1 && prices[i] >= prices[i + 1])
                i++;
            v = prices[i];
            while (i < prices.size() - 1 && prices[i] <= prices[i + 1])
                i++;
            p = prices[i];
            res += p - v;
        }

        return res;
    }
};