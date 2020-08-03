#include <deque>
#include <vector>

class Solution
{
public:
    std::vector<int> productExceptSelf(std::vector<int> &nums)
    {
        std::vector<int> res;
        std::deque<int> l, r;

        l.push_back(nums.front());
        r.push_back(nums.back());

        for (int i = 1; i < nums.size(); i++)
        {
            l[i] = l[i - 1] * nums[i];
            r[nums.size() - 1 - i] = r[nums.size() - i] * nums[nums.size() - 1 - i];
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (i == 0)
                res.push_back(r[1]);
            else if (i == nums.size() - 1)
                res.push_back(l[i - 1]);
            else
                res.push_back(l[i - 1] * r[i + 1]);
        }

        return res;
    }
};