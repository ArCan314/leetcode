#include <vector>
#include <algorithm>
#include <iostream>

class Solution
{
public:
    int maxArea(const std::vector<int> &height)
    {
        int l = 0, r = height.size() - 1;
        int max_area = (r - l) * std::min(height[l], height[r]);

        while (l < r)
        {
            if (height[l] < height[r])
            {
                int temp = height[l];
                while (height[l] <= temp && l < r)
                {
                    l++;
                }
            }
            else
            {
                int temp = height[r];
                while (height[r] <= temp && l < r)
                {
                    r--;
                }
            }
            max_area = std::max(max_area, (r - l) * std::min(height[l], height[r]));
        }

        return max_area;
    }
};

int main()
{
    std::vector<int> in{1, 8, 6, 2, 5, 4, 8, 3, 7};
    std::cout << Solution().maxArea(in) << std::endl;
    return 0;
}