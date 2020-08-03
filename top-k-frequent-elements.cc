#include <vector>
#include <map>
#include <algorithm>
#include <queue>

class Solution
{
public:
    std::vector<int> topKFrequent(std::vector<int> &nums, int k)
    {
        std::vector<int> res;
        std::map<int, int> freq;

        for (const auto &num : nums)
            freq[num] += 1;

        auto comp = [](const std::pair<int, int> &a, const std::pair<int, int> &b){ return a.second < b.second; };
        std::priority_queue<std::pair<int, int>,  std::vector<std::pair<int, int>>, decltype(comp)> que(comp);

        for (const auto &p : freq)
            que.push(p);

        for (int i = 0; i < k; i++)
        {
            res.push_back(que.top().first);
            que.pop();
        }

        return res;
    }
};