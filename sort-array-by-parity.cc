#include <vector>
#include <algorithm>

class Solution
{
public:
    std::vector<int> sortArrayByParity(std::vector<int> &A)
    {
        sortArrayByParityDoublePtr(A);
    }

    std::vector<int> sortArrayByParitySTL(std::vector<int> &A)
    {
        std::partition(A.begin(), A.end(), [](int a) { return !(a % 2); });
        return A;
    }

    std::vector<int> sortArrayByParityDoublePtr(std::vector<int> &A)
    {
        int l = 0, r = A.size() - 1;
        while (l < r)
        {
            if (A[l] % 2)
            {
                for (; l < r; r--)
                    if (A[r] % 2 == 0)
                        break;
                std::swap(A[l], A[r]);
            }
            l++;
        }
        return A;
    }
};