#include <vector>

class Solution
{
public:
    void rotate(std::vector<int> &nums, int k)
    {
        rotateVector(nums, k);
    }

    void rotateVector(std::vector<int> &nums, int k)
    {
        std::vector<int> res(nums.size(), 0);
        int count = 0;
        int ind = k % nums.size();
        while (count < nums.size())
        {
            res[ind] = nums[count++];
            ind = (ind + 1) % nums.size();
        }
        nums.swap(res);
    }
};