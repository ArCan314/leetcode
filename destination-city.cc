#include <string>
#include <vector>
#include <map>

class Solution
{
public:
    std::string destCity(std::vector<std::vector<std::string>> &paths)
    {
        std::map<std::string, int> out_deg;
        for (const auto &sv : paths)
        {
            out_deg[sv[1]] = out_deg[sv[1]];
            out_deg[sv[0]]++;
        }

        std::string res;
        for (const auto &[str, val] : out_deg)
        {
            if (val == 0)
            {
                res = str;
                break;
            }
        }
        return res;
    }
};