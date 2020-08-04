#include <vector>
#include <unordered_set>
#include <algorithm>

class Solution
{
public:
    std::vector<int> intersectMultiSet(std::vector<int> &nums1, std::vector<int> &nums2)
    {
        std::unordered_multiset<int> nums1_set(nums1.begin(), nums1.end());
        std::vector<int> res;
        for (const int tar : nums2)
        {
            if (auto i = nums1_set.find(tar); i != nums1_set.end())
            {
                nums1_set.erase(i);
                res.push_back(tar);
            }
        }
        return res;
    }

    std::vector<int> intersect(std::vector<int> &nums1, std::vector<int> &nums2) // O(max{n logn, m logm})
    {
        std::sort(nums1.begin(), nums1.end()); // O(n logn)
        std::sort(nums2.begin(), nums2.end()); // O(m logm)

        std::vector<int> res;

        int i, j;
        i = j = 0;

        while (i < nums1.size() && j < nums2.size()) // O(m + n)
        {
            if (nums1[i] < nums2[j])
                i++;
            else if (nums1[i] > nums2[j])
                j++;
            else
            {
                res.push_back(nums1[i]);
                i++, j++;
            }
        }

        return res;
    }
};