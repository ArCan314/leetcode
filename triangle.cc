class Solution {
public:
    int min(int a, int b) noexcept { return a < b ? a : b;}
int minimumTotal(vector<vector<int>> &triangle)
{
	auto dp = vector<vector<int>>(triangle.size(), vector<int>(triangle.size(), 0));
	for (int i = 0; i < triangle.size(); i++)
		for (int j = 0, k = 0; j < triangle.size() - i; j++, k++)
			dp[i][j] = triangle[j + i][k];

	for (int i = triangle.size() - 1; i > 0; i--)
		for (int j = 0, k = i - 1; j < i; j++, k--)
			dp[j][k] = min(dp[j + 1][k], dp[j][k + 1]) + dp[j][k];

	return dp[0][0];
}
};