#include <vector>
#include <algorithm>

class Solution
{
public:
    void nextPermutation(std::vector<int> &nums)
    {
        nextPermutationSTL(nums);
    }

    void nextPermutationSTL(std::vector<int> &nums)
    {
        std::next_permutation(nums.begin(), nums.end());
    }

    void nextPermutationIter(std::vector<int> &nums)
    {
        int i = nums.size() - 1, j = nums.size();
        while (i > 0)
        {
            if (nums[i] > nums[i - 1])
            {
                for (j = i; j < nums.size(); j++)
                    if (nums[j] <= nums[i - 1])
                        break;
                std::swap(nums[i - 1], nums[j - 1]);
                // std::cout << "swap " << i - 1 << " and " << j - 1 << std::endl;
                break;
            }
            i--;
        }
        // std::cout << "i: " << i << ", j: " << j << std::endl;
        std::reverse(nums.begin() + i, nums.end());
    }
};