#include <vector>

class BinaryMatrix {
  public:
    int get(int x, int y);
    std::vector<int> dimensions();
};

/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution
{
public:
    int _binarySearch(BinaryMatrix &mat, int n, int l, int r)
    {
        if (l >= r)
            return -1;
        
        int mid = (l + r) / 2;
        int res = -1;
        if (mat.get(n, mid))
        {
            int temp = _binarySearch(mat, n, l, mid);
            if (temp != -1)
                res = temp;
            else
                res = mid;
        }
        else
        {
            res = _binarySearch(mat, n, mid + 1, r);
        }
        return res;
    }

    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix)
    {
        auto size_v = binaryMatrix.dimensions();
        int lm = 101;
        for (int i = 0; i < size_v[0]; i++)
        {
            if (binaryMatrix.get(i, size_v[1] - 1))
                lm = std::min(lm, _binarySearch(binaryMatrix, i, 0, size_v[1]));
        }
        return lm == 101 ? -1 : lm;
    }
};