#include <vector>

class Solution
{
public:
    int maxProfit(std::vector<int> &prices)
    {
        if (prices.size() > 1)
        {
            std::vector<int> diff(prices.begin(), prices.end());

            for (int i = 1; i < prices.size(); i++)
                diff[i] = prices[i] - prices[i - 1];
            diff[0] = 0;

            int max = diff[0], temp;

            for (int i = 1; i < prices.size(); i++)
            {
                temp = diff[i - 1] + diff[i];
                if (diff[i] < temp)
                    diff[i] = temp;

                if (max < diff[i])
                    max = diff[i];
            }
            return max;
        }
        else
            return 0;
    }
};