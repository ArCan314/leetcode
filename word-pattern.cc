#include <string>
#include <unordered_map>
#include <unordered_set>

class Solution
{
public:
    bool wordPattern(const std::string &pattern, const std::string &str)
    {
        std::unordered_map<char, std::string> pat_match;
        std::unordered_set<std::string> pat_strs;

        int pat_cur = 0;
        int str_cur = 0;
        while (pat_cur < pattern.size())
        {
            std::string word;
            for (; str_cur < str.size(); str_cur++)
            {
                if (str[str_cur] == ' ')
                {
                    str_cur++; // skip space
                    break;
                }
                word.push_back(str[str_cur]);
            }

            if (word.empty())
                return false;

            if (pat_strs.find(word) != pat_strs.end())
            {
                if (const auto pat_pos = pat_match.find(pattern[pat_cur]); pat_pos != pat_match.end())
                {
                    if (pat_pos->second != word)
                        return false;
                }
                else // duplicated pattern str
                {
                    return false;
                }
            }
            else
            {
                if (pat_match.find(pattern[pat_cur]) != pat_match.end())
                {
                    return false;
                }
                else
                {
                    pat_strs.insert(word);
                    pat_match[pattern[pat_cur]] = word;
                }
            }

            pat_cur++;
        }

        if (str_cur != str.size())
            return false;

        return true;
    }
};