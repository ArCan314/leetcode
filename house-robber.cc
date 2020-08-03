class Solution {
public:
    int max(int a, int b) noexcept { return a > b ? a : b;}
    
    int rob(vector<int>& nums) 
    {
        int *arr = new int[nums.size()];
        int res = 0;
        if (nums.size() <= 2)
        {
            for (int i = 0; i< nums.size(); i++)
                res = max(res, nums[i]);
        }
        else if (nums.size() <= 3)
        {
            arr[0] = nums[0], arr[1] = nums[1];
            arr[2] = arr[0] + nums[2];
            for (int i = 0; i < nums.size(); i++)
                res = max(res, arr[i]);
        }
        else
        {
            arr[0] = nums[0], arr[1] = nums[1], arr[2] = nums[2] + arr[0];
            for (int i = 0; i < 3; i++)
                res = max(res, arr[i]);
            
            for (int i = 3; i < nums.size(); i++)
            {
                arr[i] = nums[i] + max(arr[i - 2], arr[i - 3]);
                res = max(arr[i], res);
            }
        }
        
        return res;
    }
};