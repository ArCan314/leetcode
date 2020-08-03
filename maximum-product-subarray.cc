class Solution {
public:
    
    struct p
    {
        int to_pos;
        int to_neg;
    };
    
    int maxProduct(vector<int>& nums) 
    {
        p *dp = new p[nums.size()]();
        dp[0].to_pos = nums[0];
        dp[0].to_neg = 0;
        
        int res = nums[0];
        
        for (int i = 1; i < nums.size(); i++)
        {
            dp[i].to_pos = max({nums[i], dp[i - 1].to_pos * nums[i], dp[i - 1].to_neg * nums[i]});
            dp[i].to_neg = min({nums[i], dp[i - 1].to_pos * nums[i], dp[i - 1].to_neg * nums[i]});
            res = max({res, dp[i].to_neg, dp[i].to_pos});
        }
        
        delete[] dp;
        return res;
    }
};