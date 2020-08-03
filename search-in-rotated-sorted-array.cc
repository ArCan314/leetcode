#include <vector>

class Solution
{
private:
    int binarySearch(std::vector<int> &nums, int l, int r, int target)
    {
        int ind = -1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (nums[mid] < target)
                l = mid + 1;
            else if (nums[mid] > target)
                r = mid - 1;
            else
            {
                ind = mid;
                break;
            }
        }
        return ind;
    }

public:
    int search(std::vector<int> &nums, int target)
    {
        if (nums.size() == 0)
            return -1;

        int pivot_index, l = 0 ,r = nums.size() - 1;

        while (nums[l] > nums[r])
        {
            if (r == l + 1)
                l = r;
            else
            {
                int mid = (r + l) / 2;
                if (nums[mid] > nums[l])
                    l = mid;
                else
                    r = mid;
            }
        }

        pivot_index = l;

        l = 0, r = nums.size() - 1;
        int res = -1;
        
        while (l <= r)
        {
            int mid = (l + r) / 2;
            int cvt = (mid + l) % nums.size();


            if (nums[cvt] < target)
                l = mid + 1;
            else if (nums[cvt] > target)
                r = mid - 1;
            else
            {
                res = cvt;
                break;
            }
        }   

        return res;
    }
};