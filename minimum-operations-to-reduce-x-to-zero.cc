#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

class Solution
{
public:
    int minOperations(std::vector<int> &nums, int x)
    {
        return minOperationMap(nums, x);
    }

    int minOperationMap(const std::vector<int> &nums, int x)
    {
        std::unordered_map<int, int> lsum, rsum;

        int sum = 0;
        int size = nums.size();
        for (int i = 0; i < size; i++)
        {
            sum += nums[i];
            if (sum > x)
                break;
            lsum[sum] = i;
        }

        sum = 0;
        for (int i = size - 1; i >= 0; i--)
        {
            sum += nums[i];
            if (sum > x)
                break;
            rsum[sum] = i;
        }

        int res = 0x7fffffff;
        for (const auto [l, ind] : lsum)
        {
            if (l == x)
            {
                res = std::min(ind + 1, res);
                continue;
            }

            if (auto iter = rsum.find(x - l); iter != rsum.end() && iter->second > ind)
                res = std::min(ind + 1 + size - iter->second, res);
        }

        if (rsum.count(x))
            res = std::min(size - rsum[x], res);

        return (res == 0x7fffffff) ? -1 : res;
    }

    void minOperationsRecursionImpl(std::vector<int> &nums, int sum, int l, int r, int &res, int count)
    {
        // std::cout << "F(sum: " << sum << ", <l, r>: <" << l << ", " << r << ">, res: " << res << ", count: " << count << ")" << std::endl;
        if (sum < 0)
            return;
        else if (sum == 0)
        {
            res = std::min(count, res);
            return;
        }

        if (count >= res)
            return;

        if (l > r)
        {
            res = -1;
            return;
        }

        if (nums[l] > nums[r])
        {
            minOperationsRecursionImpl(nums, sum - nums[l], l + 1, r, res, count + 1);
            minOperationsRecursionImpl(nums, sum - nums[r], l, r - 1, res, count + 1);
        }
        else
        {
            minOperationsRecursionImpl(nums, sum - nums[r], l, r - 1, res, count + 1);
            minOperationsRecursionImpl(nums, sum - nums[l], l + 1, r, res, count + 1);
        }
    }

    int minOperationsRecursion(std::vector<int> &nums, int x) // TLE
    {
        int res = 0x7fffffff;
        minOperationsRecursionImpl(nums, x, 0, nums.size() - 1, res, 0);
        return (res == 0x7fffffff) ? -1 : res;
    }
};