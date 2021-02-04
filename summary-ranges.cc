#include <vector>
#include <string>

class Solution
{
public:
    std::string genStr(int l, int r)
    {
        return (l == r) ? std::to_string(l) : (std::to_string(l) + "->" + std::to_string(r));
    }

    std::vector<std::string> summaryRanges(std::vector<int> &nums)
    {
        if (!nums.size())
            return {};
        int l, r;
        l = r = nums[0];
        std::vector<std::string> res;

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == r + 1)
                r++;
            else
            {
                res.push_back(std::move(genStr(l, r)));
                l = r = nums[i];
            }
        }

        res.push_back(std::move(genStr(l, r)));

        return res;

    }
};