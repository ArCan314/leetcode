// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution
{
public:
    int firstBadVersion(int n)
    {
        int l = 1, r = n;
        while (l < r)
        {
            int mid = (l + r) / 2;
            if (isBadVersion(mid))
            {
                r = mid;
            }
            else
            {
                l = mid;
            }
        }
        return l;
    }
};