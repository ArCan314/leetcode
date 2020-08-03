class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) 
    {
        
        if (matrix.size() == 0 || matrix.front().size() == 0)
            return 0;
        
        auto dp = vector<vector<int>>(matrix.size(), vector<int>(matrix.front().size(), 0));
        int res = 0;
        
        for (int i = 0; i < matrix.size(); i++)
        {
            dp[i][0] = ((matrix[i][0] == '1') ? 1 : 0);
            res = ((matrix[i][0] == '1') ? 1 : res);
        }
        
        for (int i = 0; i < matrix.front().size(); i++)
        {
            dp[0][i] = ((matrix[0][i] == '1') ? 1 : 0);
            res = ((matrix[0][i] == '1') ? 1 : res);
        }
        
        for (int i = 1; i < matrix.size(); i++)
            for (int j = 1; j < matrix.front().size(); j++)
            {
                int temp = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]});
                if (matrix[i][j] == '1')
                    dp[i][j] = temp + 1;
                else
                    dp[i][j] = 0;
                
                res = max(res, dp[i][j]);
            }
        
        return res * res;
    }
};