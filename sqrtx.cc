class Solution
{
public:
    int mySqrt(int x)
    {
        if (!x)
            return 0;

        unsigned res = 1;
        for (res = 1; res * res <= x; res++)
            ;
        return res - 1;
    }
};