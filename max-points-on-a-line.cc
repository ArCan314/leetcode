#include <vector>
#include <map>
#include <set>

class Solution
{
public:
    using LL = long long;
    using Line = std::pair<std::pair<int, int>, std::pair<int ,int>>;
    int maxPoints(std::vector<std::vector<int>> &points)
    {
        if (points.size() < 2)
            return points.size();
        std::set<std::pair<double, double>> kb_line;
        std::set<int> vert_lines;
        std::map<Line, int> lines;
        for (int i = 0; i < points.size(); i++)
            for (int j = i + 1; j < points.size(); j++)
            {
                Line temp{{points[i][0], points[i][1]}, {points[i][0] - points[j][0], points[i][1] - points[j][1]}};
                if (temp.second.first == 0)
                {
                    if (temp.second.second != 0)
                    {
                        if (vert_lines.find(temp.first.first) == vert_lines.end())
                        {
                            vert_lines.insert(temp.first.first);
                            lines[temp] = 0;
                        }
                    }
                }
                else
                {
                    double slope = 1.0 * temp.second.second / temp.second.first;
                    double shift = 1.0 * temp.first.second - slope * temp.first.first;
                    if (kb_line.find({slope, shift}) == kb_line.end())
                    {
                        kb_line.insert({slope, shift});
                        lines[temp] = 0;
                    }
                }

            }

        int res = 0;
        if (lines.size() == 0)
            return points.size();
        for (auto &line : lines)
        {
            // std::cout << "VecO: (" << line.first.first.first << ", " << line.first.first.second << "), "
            //    << "Dir: (" << line.first.second.first << ", " << line.first.second.second << ")" << std::endl;
            for (int i = 0; i < points.size(); i++)
            {
                std::pair<LL, LL> temp{points[i][0], points[i][1]};
                temp.first -= line.first.first.first;
                temp.second -= line.first.first.second;
                if (line.first.second.first * temp.second == line.first.second.second * temp.first)
                    line.second++; 
            }
            res = std::max(res, line.second);
        }
        return res;
    }
};