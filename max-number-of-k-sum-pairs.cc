#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>

class Solution
{
public:
    int maxOperations(std::vector<int> &nums, int k)
    {
        return maxOperationsGreedy(nums, k);
    }

    int maxOperationsGreedy(std::vector<int> &nums, int k)
    {
        std::sort(nums.begin(), nums.end());
        int l = 0, r = nums.size() - 1;
        int res = 0;
        if (k <= nums[0])
            return 0;

        while (l < r)
        {
            if (nums[l] + nums[r] > k)
                r--;
            else if (nums[l] + nums[r] < k)
                l++;
            else
            {
                res++;
                l++;
                r--;
            }
        }
        return res;
    }

    int maxOperationsHash(std::vector<int> &nums, int k)
    {
        std::unordered_map<int, int> freq;
        for (int i = 0; i < nums.size(); i++)
            freq[nums[i]]++;

        int res = 0;
        for (auto &[num, cnt] : freq)
        {
            if (auto iter = freq.find(k - num); iter != freq.end())
            {
                if (iter->first == num)
                {
                    res += iter->second / 2;
                    iter->second = (iter->second % 2) ? 1 : 0;
                }
                else
                {
                    int temp = std::min(iter->second, cnt);
                    res += temp;
                    iter->second -= temp;
                    cnt -= temp;
                }
            }
        }

        return res;
    }
};