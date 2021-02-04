#include <cmath>

class Solution
{
public:
    double myPow(double x, int n)
    {
        return myPowSTD(x, n);
    }

    double myPowSTD(double x, int n)
    {
        return std::pow(x, n);
    }

    double myPowRecursive(double x, int n)
    {
        if (n == 0)
            return 1.0;
        else if (n == 1)
            return x;
        else if (n == 0x80000000)
            return myPowRecursive(x, n + 1) * 1.0 / x;
        else if (n < 0)
            return 1.0 / myPowRecursive(x, -n);
        else
        {
            double res = myPowRecursive(x * x, n / 2);
            return (n % 2) ? (res * x) : res;
        }
    }
};