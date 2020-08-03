#include <vector>
#include <unordered_map>

class Solution
{
private:
    int res{};
    int sum{};

    void _findTargetSumWaysDfs(std::vector<int> &nums, int cur, int now)
    {
        if (now == nums.size())
        {
            res += (sum == cur);
            return;
        }

        _findTargetSumWaysDfs(nums, cur + nums[now], now + 1);
        _findTargetSumWaysDfs(nums, cur - nums[now], now + 1);
    }

    void _findTargetSumWaysBfs(std::vector<int> &nums, int S)
    {
        std::unordered_map<int, int> m;
        m[nums[0]]++;
        m[-nums[0]]++;

        for (int i = 1; i < nums.size(); i++)
        {
            std::unordered_map<int, int> temp;
            for (auto &p : m)
            {
                temp[p.first + nums[i]] += p.second;
                temp[p.first - nums[i]] += p.second;
            }

            m = std::move(temp);
        }

        for (const auto &p : m)
        {
            if (p.first == S)
            {
                res += p.second;
            }
        }
    }

    void _findTargetSumWaysDp(std::vector<int> &nums, int S)
    {
        std::array<int, 2001> dp{}, next{};

        dp[nums[0] + 1000]++;
        dp[-nums[0] + 1000]++;

        for (int i = 1; i < nums.size(); i++)
        {
            // std::array<int, 2001> next{};
            for (int j = -1000; j <= 1000; j++)
            {
                if (dp[j + 1000] > 0)
                {
                    next[j + nums[i] + 1000] += dp[j + 1000];
                    next[j - nums[i] + 1000] += dp[j + 1000];
                    dp[j + 1000] = 0;
                }
            }
            dp.swap(next);
        }

        res = dp[S + 1000];
    }

public:
    int findTargetSumWays(std::vector<int> &nums, int S)
    {
        res = 0;
        sum = S;

        if (!nums.size() || S > 1000 || S < -1000)
            return 0;

        // _findTargetSumWaysBfs(nums, S);

        _findTargetSumWaysDp(nums, S);

        // _findTargetSumWaysDfs(nums, 0, 0);
        return res;
    }
};