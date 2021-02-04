#include <vector>
#include <algorithm>

class Solution
{
public:
    int countGoodRectangles(std::vector<std::vector<int>> &rectangles)
    {
        int max_len = 0;
        for (int i = 0; i < rectangles.size(); i++)
            max_len = std::max(max_len, std::min(rectangles[i][0], rectangles[i][1]));
        
        int res = 0;
        for (int i = 0; i < rectangles.size(); i++)
            if (std::min(rectangles[i][0], rectangles[i][1]) == max_len)
                res++;

        return res;
    }
};