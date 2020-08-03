#include <vector>
#include <tuple>

class Solution
{
public:
    bool checkStraightLine(const std::vector<std::vector<int>> &coordinates) const noexcept
    {
        if (coordinates.size() <= 2)
            return true;
        
        const auto [ox, oy, dir_x, dir_y] = std::make_tuple(coordinates[0][0], coordinates[0][1], coordinates[1][0] - coordinates[0][0], coordinates[1][1] - coordinates[0][1]);

        bool res = true;
        for (const auto &v : coordinates)
            if (const auto [dx, dy] = std::make_pair(v[0] - ox, v[1] - oy); 
                dx * dir_y != dy * dir_x)
            {
                res = false;
                break;
            }
        return res;
    }
};