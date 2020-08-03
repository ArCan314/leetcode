#include <iostream>
#include <array>

const std::array<int, 20> lookup = {1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049, 177147, 531441, 1594323, 4782969, 14348907, 43046721, 129140163, 387420489, 1162261467};

class Solution
{
public:
    

    bool isPowerOfThree(int n)
    {
        for (int i = 0; i < lookup.size(); i++)
        {
            if (lookup[i] > n)
                break;
            else if (lookup[i] == n)
                return true;
        }
        return false;
    }
};


// int main()
// {
//     for (int i = 1; i > 0; i*= 3)
//         std::cout << i << ", ";
// }