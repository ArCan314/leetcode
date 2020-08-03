#include <vector>
#include <unordered_map>

class Solution {
public:
    bool checkIfExist(std::vector<int>& arr) 
    {
        std::unordered_map<int, int> s;
        for (const int &num : arr)
        {
            s[num] += 1;
        }

        for (const auto &num : s)
        {
            if (num.first * 2 == num.first)
            {
                if (num.second > 1)
                    return true;
            }
            else
            {
                if (s.count(num.first * 2))
                    return true;
            }
        }

        return false;
    }
};