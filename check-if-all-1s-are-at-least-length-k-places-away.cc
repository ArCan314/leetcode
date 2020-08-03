#include <vector>

class Solution
{
public:
    bool kLengthApart(std::vector<int> &nums, int k)
    {
        int last_pos = 0;
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] == 1)
            {
                last_pos = i;
                break;
            }

        for (int i = last_pos + 1; i < nums.size(); i++)
        {
            if (nums[i])
            {
                if (i - last_pos <= k)
                    return false;
                else
                    last_pos = i;
            }
        }
        return true;
    }
};