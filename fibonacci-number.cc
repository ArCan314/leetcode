#include <unordered_map>

class Solution
{
public:
    int fib(int N)
    {
        return fibDP(N);
    }

    int fibRecWithMemo(int N, std::unordered_map<int, int> &memo)
    {
        if (auto iter = memo.find(N); iter != memo.end())
            return iter->second;

        if (N == 0 || N == 1)
        {
            memo[N] = N;
            return N;
        }

        int res = fibRecWithMemo(N - 1, memo) + fibRecWithMemo(N - 2, memo);
        memo[N] = res;
        return res;
    }

    int fibRec(int N)
    {
        if (N == 0 || N == 1)
            return N;
        return fibRec(N - 1) + fibRec(N - 2);
    }

    int fibDP(int N)
    {
        int temp[31]{0};
        temp[1] = 1;
        for (int i = 2; i <= N; i++)
            temp[i] = temp[i - 1] + temp[i - 2];
        return temp[N];
    }

    int fibLUT(int N)
    {
        int fib_lut[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229, 832040, 1346269, 2178309, 3524578, 5702887, 9227465, 14930352, 24157817, 39088169, 63245986, 102334155, 165580141, 267914296, 433494437, 701408733, 1134903170, 1836311903};
        return fib_lut[N];
    }
};