#include <vector>
#include <iostream>

class Solution
{
public:
    int findKthPositive(std::vector<int> &arr, int k)
    {
        return findKthPositiveBS(arr, k);
    }

    int findKthPositiveBS(std::vector<int> &arr, int k)
    {
        int left = 0, right = arr.size();

        while (left < right)
        {
            int mid = (left + right) / 2;
            if (arr[mid] - mid - 1 < k)
                left = mid + 1;
            else
                right = mid;
            
            // std::cout << left << ", " << right << ", " << mid << ", " << arr[mid] - mid - 1 << endl;
        }
        // std::cout << left << ", " << right << endl;
        return left + k;
    }

    int findKthPositiveEnum(std::vector<int> &arr, int k)
    {
        int cur = 1;
        int count = 0;

        for (int i = 0; i < arr.size() && count < k; i++)
        {
            if (arr[i] == cur)
                cur++;
            else
            {
                count++;
                cur++;
                i--;
            }
        }

        while (count != k)
        {
            cur++;
            count++;
        }

        return cur - 1;
    }
};