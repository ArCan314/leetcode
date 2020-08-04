#include <vector>
#include <algorithm>

class Solution
{
public:
    std::vector<int> findDisappearedNumbersUsingSort(std::vector<int> &nums) // O(n logn)
    {
        std::vector<int> res;
        nums.push_back(nums.size() + 1);
        nums.push_back(0);
        std::sort(nums.begin(), nums.end());

        for (int i = 1; i < nums.size(); i++)
            if (nums[i] - nums[i - 1] > 1)
                for (int j = nums[i - 1] + 1; j < nums[i]; j++)
                    res.push_back(j);

        return res;
    }

    std::vector<int> findDisappearedNumbers(std::vector<int> &nums) // O(n)
    {
        std::vector<int> res;
        for (int i = 0; i < nums.size(); i++)
        {
            int temp = std::abs(nums[i]);
            if (nums[temp - 1] > 0)
                nums[temp - 1] *= -1;
        }

        for (int i = 0; i < nums.size(); i++)
            if (nums[i] > 0)
                res.push_back(i + 1);
        return res;
    }
};