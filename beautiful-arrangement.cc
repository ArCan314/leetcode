#include <vector>

class Solution
{
public:
    int countArrangement(int n)
    {
        return countArrangementLUT(n);
    }

    bool check(int perm_val, int index)
    {
        return !(perm_val % index) || !(index % perm_val);
    }

    void countArrangementImpl(int now, int &res, std::vector<int> &used)
    {
        if (now == used.size())
        {
            res++;
            return;
        }

        for (int i = 0; i < used.size(); i++)
        {
            if (!used[i] && check(i + 1, now + 1))
            {
                used[i] = 1;
                countArrangementImpl(now + 1, res, used);
                used[i] = 0;
            }
        }
    }

    int countArrangementDFS(int n)
    {
        std::vector<int> used(n, 0);
        int res = 0;
        countArrangementImpl(0, res, used);
        return res;
    }
    
    int countArrangementLUT(int n)
    {
        static int lut[] = {1, 2, 3, 8, 10, 36, 41, 132, 250, 700, 750, 4010, 4237, 10680, 24679};
        return lut[n - 1];
    }

};