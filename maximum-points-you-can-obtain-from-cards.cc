#include <vector>

class Solution
{
public:
    int maxScore(std::vector<int> &cardPoints, int k)
    {
        if (!cardPoints.size())
            return 0;
        std::vector<int> total_sum(cardPoints.size() + 1, 0);
        for (int i = 1; i <= cardPoints.size(); i++)
            total_sum[i] += total_sum[i - 1] + cardPoints[i - 1];

        int res = 0;
        for (int i = 0; i <= k; i++)
            res = std::max(res, total_sum[i] + 
                        total_sum[cardPoints.size()] - total_sum[cardPoints.size() - k + i]);

        return res;
    }
};