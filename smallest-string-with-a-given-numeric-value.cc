#include <string>

class Solution
{
public:
    std::string getSmallestString(int n, int k)
    {
        int num_z = (k - n) / 25;
        int num_a = n - num_z;
        int diff = k - 26 * num_z - num_a;

        char fill_char = (num_a >= num_z) ? 'a' : 'z';
        char r_char = (num_a >= num_z) ? 'z' : 'a';
        int start = (num_a >= num_z) ? num_a : 0;
        int end = (num_a >= num_z) ? n : num_a;
        std::string res(n, fill_char);

        for (int i = start; i < end; i++)
            res[i] = r_char;
        
        if (diff)
            res[num_a - 1] += diff;
        
        return res;

        // if (num_a >= num_z)
        // {
        //     std::string res(n, 'a');

        //     for (int i = num_a; i < n; i++)
        //         res[i] = 'z';

        //     if (diff)
        //         res[num_a - 1] += diff;

        //     return res;
        // }
        // else
        // {
        //     std::string res(n, 'z');

        //     for (int i = 0; i < num_a; i++)
        //         res[i] = 'a';

        //     if (diff)
        //         res[num_a - 1] += diff;

        //     return res;
        // }
        // return "";
    }
};