#include <string>
#include <cctype>

class Solution
{
public:
    std::string _decodeString(std::string &s, int &pos)
    {
        std::string res;
        for (; pos < s.size(); pos++)
        {
            if (std::isalpha(s[pos]))
                res.push_back(s[pos]);
            else if (std::isdigit(s[pos]))
            {
                std::string digit_temp;
                for (; s[pos] != '['; pos++)
                {
                    digit_temp.push_back(s[pos]);
                }
                int dup_times = std::stoi(digit_temp);
                pos++;
                std::string dup_str = _decodeString(s, pos);
                for (int i = 0; i < dup_times; i++)
                    res.append(dup_str);
            }
            else if (s[pos] == ']')
                break;
        }
        return res;
    }

    std::string decodeString(std::string s)
    {
        s.push_back(']');
        int pos = 0;
        return _decodeString(s, pos);
    }
};