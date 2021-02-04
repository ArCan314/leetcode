#include <vector>

class Solution
{
public:
    std::vector<bool> prefixesDivBy5(std::vector<int> &A)
    {
        std::vector<bool> res;
        int sum = 0;
        for (int i = 0; i < A.size(); i++)
        {
            sum = ((sum * 2) + A[i]) % 5;
            res.push_back(!sum);
        }
        return res;
    }
};