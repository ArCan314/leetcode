#include <string>

class Solution
{
public:
    bool canConstruct(std::string &ransomNote, std::string &magazine)
    {
        int mag_map[26]{};
        for (const auto c : magazine)
            mag_map[c - 'a']++;
        
        bool res = true;
        for (const auto c : ransomNote)
        {
            if (int &temp = mag_map[c - 'a']; temp)
                temp--;
            else
            {
                res = false;
                break;
            }
        }
        return res;
    }
};