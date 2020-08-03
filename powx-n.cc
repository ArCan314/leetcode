class Solution {
public:
    double myPow(double x, int n) {
        if (n < 0)
        {
            return myPow(1.0 / x, -n);
        }
        else if (n == 0)
        {
            return 1.0;
        }
        else if (n % 2)
        {
            return x * myPow(x, n - 1);
        }
        else
        {
            double res = myPow(x, n / 2);
            return res * res;
        }
    }
};