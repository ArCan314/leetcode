#include <vector>

class Solution
{
private:
    void genSet(std::vector<int> &nums, std::vector<int> &path, int current, int len)
    {
        if (current >= nums.size())
            return;

        if (!len)
        {
            res.push_back(path);
        }

        for (int i = current + 1; i < nums.size(); i++)
        {
            path.push_back(nums[i]);
            genSet(nums, path, i, len - 1);
            path.pop_back();
        }
    }

    std::vector<std::vector<int>> res;

public:
    std::vector<std::vector<int>> subsets(std::vector<int> &nums)
    {
        res.clear();
        std::vector<int> temp;

        res.push_back({});

        for (int len = 1; len <= nums.size(); len++)
        {
            for (int i = 0; i < nums.size() - len + 1; i++)
            {
                temp.push_back(nums[i]);
                genSet(nums, temp, i, len - 1);
                temp.pop_back();
            }
        }

        return res;
    }
};