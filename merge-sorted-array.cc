#include <vector>

class Solution
{
public:
    void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n)
    {
        int r = 0;
        for (int i = 0; i < m + n && r < n; i++)
        {
            if (nums1[i] > nums2[r])
            {
                for (int j = m + n - 1; j > i; j--)
                    std::swap(nums1[j], nums1[j - 1]);
                nums1[i] = nums2[r++];
            }
        }

        while (r < n)
        {
            nums1[m + r] = nums2[r];
            r++;
        }
    }
};