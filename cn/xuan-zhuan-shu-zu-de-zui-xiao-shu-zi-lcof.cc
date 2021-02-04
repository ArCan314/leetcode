#include <vector>

class Solution
{
public:
    int minArray(std::vector<int> &numbers)
    {
        int l = 0, r = numbers.size() - 1;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (numbers[mid] > numbers[r])
                l = mid + 1;
            else if (numbers[mid] < numbers[l])
                r = mid;
            else
                r--;
        }
        return numbers[l];
    }
};