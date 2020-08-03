#include <vector>

class Solution
{
public:
    std::vector<int> plusOne(std::vector<int> &digits)
    {
        int i;
        int c = 1;
        for (i = digits.size() - 1; i >= 0; i--)
        {
            if (c)
            {
                digits[i]++;
                c = 0;
            }
            else
            {
                break;
            }

            if (digits[i] / 10)
            {
                c = 1;
                digits[i] -= 10;
            }
        }

        if (i < 0 && c)
        {
            digits.insert(digits.begin(), 1);
            // std::vector<int> temp(digits.size() + 1, 1);

            // for (int i = 1; i < temp.size(); i++)
            // {
            //     temp[i] = digits[i - 1];
            // }
            // digits.swap(temp);
        }

        return digits;
    }
};