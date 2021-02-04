#include <vector>
#include <algorithm>

class Solution
{
public:
    std::vector<int> addToArrayForm(std::vector<int> &A, int K)
    {
        std::vector<int> k_arr;
        while (K)
        {
            k_arr.push_back(K % 10);
            K /= 10;
        }

        auto iter_a = A.rbegin();
        auto iter_k = k_arr.begin();
        std::vector<int> res;
        int sum = 0, carry = 0;

        while (iter_a != A.rend() && iter_k != k_arr.end())
        {
            sum = carry + *(iter_a++) + *(iter_k++);
            carry = sum / 10;
            sum %= 10;
            res.push_back(sum);
        }

        while (iter_a != A.rend())
        {
            sum = carry + *(iter_a++);
            carry = sum / 10;
            sum %= 10;
            res.push_back(sum);
        }

        while (iter_k != k_arr.end())
        {
            sum = carry + *(iter_k++);
            carry = sum / 10;
            sum %= 10;
            res.push_back(sum);
        }

        if (carry)
            res.push_back(1);

        std::reverse(res.begin(), res.end());

        return res;
    }
};