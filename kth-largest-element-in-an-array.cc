#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

static int get_random_index(int l, int r)
{
    static std::random_device dev;
    static std::mt19937 rng(dev());
    std::uniform_int_distribution<int> dist(l, r - 1);
    return dist(rng);
}

class Solution
{
public:
    int _findKthLargest(std::vector<int> &nums, int k, int l, int r)
    {
        if (l >= r)
            return 0;

        int pivot_ind = get_random_index(l, r);
        int pivot = nums[pivot_ind];
        std::swap(nums[l], nums[pivot_ind]);

        int i = l;

        for (int j = l + 1; j < r; j++)
        {
            if (nums[j] > pivot)
            {
                std::swap(nums[j], nums[++i]);
            }
        }

        std::swap(nums[l], nums[i]);

        int cnt = i - l;

        if (cnt == k - 1)
        {
            return pivot;
        }
        else if (cnt < k - 1)
        {
            return _findKthLargest(nums, k - cnt - 1, i + 1, r);
        }
        else
        {
            return _findKthLargest(nums, k, l, i);
        }
    }

    int findKthLargest(std::vector<int> &nums, int k)
    {
        std::nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), std::greater<int>());
        return nums[k - 1];
    }
};