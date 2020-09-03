#include <vector>

class Solution
{
public:
    std::vector<int> numsSameConsecDiff(int N, int K)
    {
        std::vector<int> res;
        if (N == 1)
            return {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        for (int i = 1; i <= 9; i++)
            _numsSameConsecDiff(res, 1, i, N, K);
        return res;
    }

private:
    static constexpr int append(int num, int digit) noexcept { return num * 10 + digit; }
    static constexpr int lastDigit(int num) noexcept { return num % 10; }

    void _numsSameConsecDiff(std::vector<int> &res, int cur, int num, int n, int k)
    {
        // cout << "cur: " << cur << ", num: " << num << endl;
        if (cur == n)
        {
            res.push_back(num);
            return;
        }
        
        for (int i = 0; i <= 9; i++)
        {
            int last_digit = lastDigit(num);
            if (k)
            {
                if (last_digit - k == i)
                    _numsSameConsecDiff(res, cur + 1, append(num, i), n, k);
                if (last_digit + k == i)
                    _numsSameConsecDiff(res, cur + 1, append(num, i), n, k);
            }
            else if (last_digit == i)
                _numsSameConsecDiff(res, cur + 1, append(num, i), n, k);
                
        }
    }
};