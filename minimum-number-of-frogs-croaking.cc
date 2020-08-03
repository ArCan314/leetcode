#include <string>
#include <vector>
#include <algorithm>

class Solution
{
public:
    int minNumberOfFrogs(std::string &croakOfFrogs)
    {
        int v[5]{};
        std::string &s = croakOfFrogs;
        int ind_map[26]{};
        ind_map['r' - 'a'] = 1;
        ind_map['o' - 'a'] = 2;
        ind_map['a' - 'a'] = 3;
        ind_map['k' - 'a'] = 4;
        int res = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'c')
            {
                v[0]++;
                if (v[4])
                    v[4]--;
            }
            else
            {
                int index = ind_map[s[i] - 'a'];

                if (v[index - 1] <= 0)
                    return -1;
                else
                {
                    v[index - 1]--;
                    v[index]++;
                }
            }
        }
        for (int i = 0; i < 4; i++)
            if (v[i])
                return -1;

        return v[4];
    }
};