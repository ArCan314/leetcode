#include <unordered_set>
#include <iostream>

class Solution
{
public:
    static std::unordered_set<int> happy_nums;

    const int sqrSumOfEachDigit(int num) const noexcept
    {
        int res = 0;
        while (num)
        {
            res += (num % 10) * (num % 10);
            num /= 10;
        }
        return res;
    }

    bool isHappy(int n)
    {
        happy_nums.insert(1);

        if (happy_nums.count(n))
            return true;
        else
        {
            std::unordered_set<int> temp;
            bool is_happy = false;
            while (true)
            {
                int sqr = sqrSumOfEachDigit(n);
                if (happy_nums.count(sqr)) // is happy
                {
                    for (const auto &i : temp)
                    {
                        happy_nums.insert(i);
                    }
                    is_happy = true;
                    break;
                }
                else if (temp.count(sqr)) // has circle?
                {
                    is_happy = false;
                    break;
                }
                else
                {
                    temp.insert(n);
                    n = sqr;
                }
            }

            return is_happy;
        }
    }
};

std::unordered_set<int> Solution::happy_nums{1, 7, 10, 13, 19, 23, 28, 31, 32, 44, 49, 68, 70, 79, 82, 86, 91, 94, 97, 100, 103, 109, 129, 130, 133, 139, 167, 176, 188, 190, 192, 193, 203, 208, 219, 226, 230, 236, 239, 262, 263, 280, 291, 293, 301, 302, 310, 313, 319, 320, 326, 329, 331, 338, 356, 362, 365, 367, 368, 376, 379, 383, 386, 391, 392, 397, 404, 409, 440, 446, 464, 469, 478, 487, 490, 496, 536, 556, 563, 565, 566, 608, 617, 622, 623, 632, 635, 637, 638, 644, 649, 653, 655, 656, 665, 671, 673, 680, 683, 694, 700, 709, 716, 736, 739, 748, 761, 763, 784, 790, 793, 802, 806, 818, 820, 833, 836, 847, 860, 863, 874, 881, 888, 899, 901, 904, 907, 910, 912, 913, 921, 923, 931, 932, 937, 940, 946, 
964, 970, 973, 989, 998};

// int main()
// {
//     for (int i = 0; i < 1000; i++)
//         if (Solution().isHappy(i))
//         {
//             std::cout << i << ", ";
//         }
//     return 0;
// }