#include <vector>
#include <algorithm>

class Solution
{
public:
    int numRescueBoats(std::vector<int> &people, int limit)
    {
        std::sort(people.begin(), people.end());
        int l = 0, r = people.size() - 1;
        int res = 0;

        while (l < r)
        {
            int weight_l = people[l];
            int weight_r = people[r];
            if (weight_l + weight_r <= limit)
                l++;
            res++;
            r--;
        }
        if (l == r)
            res++;
        return res;
    }
};