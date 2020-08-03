#include <vector>
#include <deque>

class Solution
{
public:
    template <typename T>
    using Vec2D = std::vector<std::vector<T>>;
    template <typename T1, typename T2>
    using PairQ = std::deque<std::pair<T1, T2>>;

    Vec2D<int> floodFill(Vec2D<int> &image, int sr, int sc, int newColor)
    {
        int cols = image.front().size();
        int rows = image.size();
        int origin_color = image[sr][sc];
        Vec2D<bool> is_visited(rows, std::vector<bool>(cols, false));

        PairQ<int, int> q;
        q.push_back({sr, sc});
        while (q.size())
        {
            const auto &[r, c] = q.front();
            if (r > 0) // u
                if (!is_visited[r - 1][c] && image[r - 1][c] == origin_color)
                    q.push_back({r - 1, c});
            if (r < rows - 1) // d
                if (!is_visited[r + 1][c] && image[r + 1][c] == origin_color)
                    q.push_back({r + 1, c});
            if (c > 0) // l
                if (!is_visited[r][c - 1] && image[r][c - 1] == origin_color)
                    q.push_back({r, c - 1});
            if (c < cols - 1) // r
                if (!is_visited[r][c + 1] && image[r][c + 1] == origin_color)
                    q.push_back({r, c + 1});

            image[r][c] = newColor;
            is_visited[r][c] = true;
            q.pop_front();
        }

        return image;
    }
};