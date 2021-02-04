#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void bubbleSort(vector<int> &nums) // bubble sort, time complexity O(n^2), TLE
    {
        for (int i = 0; i < nums.size() - 1; i++)
            for (int j = nums.size() - 1; j > i; j--)
                if (nums[j] < nums[j - 1])
                    swap(nums[j], nums[j - 1]);
    }
    
    void selectionSort(vector<int> &nums) // selection sort, time complexity O(n^2), TLE
    {
        for (int i = 0; i < nums.size() - 1; i++)
        {
            int min_ind = i;
            for (int j = i + 1; j < nums.size(); j++)
                if (nums[j] < nums[min_ind])
                    min_ind = j;
            
            swap(nums[min_ind], nums[i]);
        }
    }
    
    void insertionSort(vector<int> &nums) // insertion sort, time complexity O(n^2), TLE
    {
        for (int i = 1; i < nums.size(); i++)
        {
            int key = nums[i];
            
            int j = i - 1;
            while (j >= 0 && nums[j] > key)
            {
                swap(nums[j], nums[j + 1]);
                j--;
            }
            
            nums[j + 1] = key;
        }
    }
    
    void cardinalSort(vector<int> &nums) // cardinal sort, time complexity O(n), space complexity O(k + n), time: 48ms, mem: 16.9MB
    {
        int minimum, maximum;
        minimum = maximum = nums[0];
        
        for (int i = 0; i < nums.size(); i++)
        {
            minimum = min(minimum, nums[i]);
            maximum = max(maximum, nums[i]);
        }
        
        vector<int> card(maximum - minimum + 1, 0);
        vector<int> temp = nums;
        
        for (int i = 0; i < nums.size(); i++)
            card[nums[i] - minimum]++;
        
        
        for (int i = 1; i < card.size(); i++)
            card[i] += card[i - 1];
        
        for (int i = 0; i < nums.size(); i++)
        {
            temp[card[nums[i] - minimum] - 1] = nums[i];
            card[nums[i] - minimum]--;
        }
        
        nums = temp;
    }
    
    int abs(int num) { return (num < 0) ? -num : num; }
    
    void radixSort(vector<int> &nums) // radix sort, time complexity O(dn), space complexity O(n), time: 60ms, mem:22.2MB
    {
        vector<vector<int>> radix_arr(10);
        
        radix_arr[1] = nums;
        int dividened = 1;
        constexpr int mod = 10;
        
        int count = 1;
        while (count)
        {
            count = 0;
            vector<vector<int>> temp_radix(10);
            
            for (const auto &arr : radix_arr)
                for (int i = 0; i < arr.size(); i++)
                    temp_radix[(abs(arr[i]) / dividened) % mod].push_back(arr[i]);
            
            radix_arr.swap(temp_radix);
            for (int i = 1; i < radix_arr.size(); i++)
                count += radix_arr[i].size();
            
            dividened *= mod;
        }
        
        vector<int> negatives;
        vector<int> positives;
        
        for (int i = 0; i < radix_arr[0].size(); i++)
            if (radix_arr[0][i] < 0)
                negatives.push_back(radix_arr[0][i]);
            else
                positives.push_back(radix_arr[0][i]);
        
        int k = 0;
        for (int i = negatives.size() - 1; i >= 0; i--)
            nums[k++] = negatives[i];
        
        for (int i = 0; i < positives.size(); i++)
            nums[k++] = positives[i];
    }
    
    void _merge(vector<int> &nums, vector<int> &aux, int l, int r)
    {
        int mid = (l + r) / 2;
        int i, j, k;
        i = l;
        j = mid + 1;
        k = l;
        
        while (i <= mid && j <= r)
            if (nums[i] <= nums[j])
                aux[k++] = nums[i++];
            else
                aux[k++] = nums[j++];
        
        while (i <= mid)
            aux[k++] = nums[i++];
        
        while (j <= r)
            aux[k++] = nums[j++];
        
        for (int i = l; i <= r; i++)
            nums[i] = aux[i];
    }
    
    void _mergeSort(vector<int> &nums, vector<int> &aux, int l, int r)
    {
        if (l >= r)
            return;
        
        int mid = (l + r) / 2;
        _mergeSort(nums, aux, l, mid);
        _mergeSort(nums, aux, mid + 1, r);
        _merge(nums, aux, l, r);
    }
    
    void mergeSort(vector<int> &nums) // merge sort, time complexity O(nlgn), space complexity O(n), time: 60ms, mem: 16.4MB 
    {
        vector<int> aux(nums.size());
        _mergeSort(nums, aux, 0, nums.size() - 1);
    }
    
    constexpr int _parent(int ind) const noexcept
    {
        return (ind + 1) / 2 - 1; 
    }
    
    constexpr int _left(int ind) const noexcept
    {
        return 2 * ind + 1;
    }
    
    constexpr int _right(int ind) const noexcept
    {
        return 2 * ind + 2;
    }
    
    void _maxHeapify(vector<int> &nums, int ind, int heap_size)
    {
        int max_ind = ind;
        int left_ind = _left(ind);
        int right_ind = _right(ind);
        
        if (left_ind < heap_size && nums[left_ind] > nums[max_ind])
            max_ind = left_ind;
        
        if (right_ind < heap_size && nums[right_ind] > nums[max_ind])
            max_ind = right_ind;
        
        if (max_ind != ind)
        {
            swap(nums[ind], nums[max_ind]);
            _maxHeapify(nums, max_ind, heap_size);
        }
    }
    
    void _buildMaxHeap(vector<int> &nums)
    {
        for (int i = _parent(nums.size() - 1); i >= 0; i--)
            _maxHeapify(nums, i, nums.size());
    }
    
    
    void heapSort(vector<int> &nums) // heap sort, time complexity O(nlgn), space complexity O(1), time: 68ms, mem:15.9MB
    {
        _buildMaxHeap(nums);
        for (int i = nums.size() - 1; i > 0; i--)
        {
            swap(nums[i], nums[0]);
            _maxHeapify(nums, 0, i);
        }
    }
    
    
    void _quickSort(vector<int> &nums, int l, int r)
    {
        if (l >= r)
            return;
        
        int pivot = nums[l];
        int i = l;
        
        for (int j = l + 1; j <= r; j++)
            if (nums[j] < pivot)
                swap(nums[j], nums[++i]);
        
        swap(nums[l], nums[i]);
        _quickSort(nums, l, i - 1);
        _quickSort(nums, i + 1, r);
    }
    
    void quickSort(vector<int> &nums) // quick sort, time complexity O(nlgn), space complexity O(1), time: 60ms, mem:16MB
    {
        _quickSort(nums, 0, nums.size() - 1);
    }
    
    void stlSort(vector<int> &nums) // time: 40ms, mem:16.1MB
    {
        sort(nums.begin(), nums.end());
    }
    
    vector<int> sortArray(vector<int>& nums) {
        stlSort(nums);
        return nums;
    }
};