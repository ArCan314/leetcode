#include <vector>
#include <string>
#include <algorithm>

class Solution
{
public:
    std::string longestCommonPrefix(std::vector<std::string> &strs)
    {
        if (!strs.size())
        {
            return "";
        }

        int len, min_len = strs.front().size();
        std::string prefix;

        for (const auto &s : strs)
        {
            min_len = std::min(static_cast<int>(s.size()), min_len);
        }

        for (len = 0; len < min_len; len++)
        {
            char temp = strs.front().at(len);
            bool is_failed = false;
        
            for (int i = 1; i < strs.size(); i++)
            {
                if (strs[i][len] != temp)
                {
                    is_failed = true;
                    break;
                }
            }

            if (is_failed)
            {
                break;
            }
            else
            {
                prefix.push_back(temp);
            }
        }

        return prefix;
    }
};