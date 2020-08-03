#include <vector>
#include <algorithm>

class Solution
{
public:
    int trap(std::vector<int> &height)
    {
        if (!height.size())
            return 0;
        std::vector<int> l_max(height.size(), height.front()), 
                         r_max(height.size(), height.back());
        int res = 0;
        for (int i = 1; i < height.size(); i++)
        {
            l_max[i] = std::max(l_max[i - 1], height[i]);
            r_max[height.size()-i-1] = std::max(r_max[height.size()-i], height[height.size()-i-1]);
        }
        for (int i = 0; i < height.size(); i++)
        {
            if (int min_max = std::min(l_max[i], r_max[i]); height[i] < min_max)
                res += min_max - height[i];
        }
        return res;
    }
};