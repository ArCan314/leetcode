#include <vector>
#include <unordered_map>

class Solution
{
public:
    int findMaxLengthN2(std::vector<int> &nums)
    {
        int res = 0;
        for (int i = 0; i < nums.size() - res; i++)
        {
            int zeros = 0;
            int max_len = 0;
            for (int j = 0; j + i < nums.size(); j++)
            {
                zeros += nums[i + j] ? -1 : 1;
                if (!zeros)
                    max_len = j + 1;
            }
            res = std::max(max_len, res);
        }
        return res;
    }

    int Max(const int a, const int b) { return a < b ? b : a; }

    int findMaxLength(std::vector<int> &nums)
    {
        std::unordered_map<int, int> p_map;
        int sum = 0;
        p_map[0] = -1;
        int res = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            // std::cout << "sum: " << sum << std::endl;
            sum += nums[i] ? -1 : 1;
            if (p_map.count(sum))
            {
                res = i - p_map[sum];
            }
            else
            {
                p_map[sum] = i;
            }
        }

        return res;
    }
};