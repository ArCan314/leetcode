class Solution {
public:
    long long uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        long long dp[100][100];
        int has_ob = 1;
        dp[0][0] = 1;
        for (int i = 0; i < obstacleGrid.front().size(); i++)
        {
            if (obstacleGrid[0][i])
                has_ob = 0;
            dp[0][i] = has_ob;
        }
        
        has_ob = 1;
        for (int i = 0; i < obstacleGrid.size(); i++)
        {
            if (obstacleGrid[i][0] == 1)
                has_ob = 0;
            dp[i][0] = has_ob;
        }
        
        for (int i = 1; i < obstacleGrid.size(); i++)
            for (int j = 1; j < obstacleGrid.front().size(); j++)
                dp[i][j] = obstacleGrid[i][j] ? 0: dp[i - 1][j] + dp[i][j - 1];
        
        return dp[obstacleGrid.size() - 1][obstacleGrid.front().size() - 1];
    }
};