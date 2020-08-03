class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        auto temp = vector<vector<int>>(grid.size(), vector<int>(grid.front().size(), 0));
        
        temp[0][0] = grid[0][0];
        for (int i = 1; i < grid.size(); i++)
        {
            temp[i][0] = temp[i - 1][0] + grid[i][0];
        }
        
        for (int i = 1; i < grid.front().size(); i++)
        {
            temp[0][i] = temp[0][i - 1] + grid[0][i];
        }
        
        for (int i = 1; i < grid.size(); i++)
            for (int j = 1; j < grid.front().size(); j++)
            {
                temp[i][j] = min(temp[i - 1][j], temp[i][j - 1]) + grid[i][j];
            }
        
        return temp[grid.size() - 1][grid.front().size() - 1];
    }
};