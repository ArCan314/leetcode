#include <string>
#include <list>
#include <stack>

class Solution
{
public:
    std::string removeKdigits(std::string num, int k)
    {
        if (!num.size() || k < 0)
            return "";
        if (k == 0)
            return num;

        std::string res;
        int i = 0;
        while (i < num.size() && num[i] == '0')
            i++;
        
        res.push_back(num[i]);
        i = i + 1;
        for (; i < num.size() && k; i++)
        {
            while (k && res.size() && num[i] < res.back())
            {
                res.pop_back();
                k--;
            }
            if (res.size() || num[i] != '0')
                res.push_back(num[i]);
        }
        if (k)
            while (res.size() && k--)
                res.pop_back();
        else
            for (; i < num.size(); i++)
                if (res.size() || num[i] != '0')
                    res.push_back(num[i]);
        
        if (!res.size())
            res.push_back('0');
        return res;
    }
};