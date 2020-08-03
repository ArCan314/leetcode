#include <vector>
#include <queue>
#include <algorithm>

class Solution
{
public:
    int lastStoneWeightV1(std::vector<int> &stones)
    {
        std::priority_queue<int, std::vector<int>> pq(stones.begin(), stones.end());
        int res = 0;

        while (pq.size())
        {
            if (pq.size() == 1)
            {
                res = pq.top();
                pq.pop();
            }
            else
            {
                int t1, t2;
                t1 = pq.top();
                pq.pop();
                t2 = pq.top();
                pq.pop();

                if (t1 != t2)
                {
                    pq.push(t1 - t2);
                }
            }
        }

        return res;
    }

    int lastStoneWeight(std::vector<int> &stones)
    {
        int res = 0;

        while (stones.size())
        {
            std::sort(stones.begin(), stones.end());
            if (stones.size() == 1)
            {
                res = stones.back();
                stones.pop_back();
            }
            else
            {
                int temp[2] = {stones[stones.size() - 1], stones[stones.size() - 2]};
                stones.pop_back();
                stones.pop_back();
                if (temp[0] != temp[1])
                {
                    stones.push_back(temp[0] - temp[1]);
                }
            }
        }

        return 0;
    }
};