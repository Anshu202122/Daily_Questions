class Solution
{
public:
    int solve(vector<vector<int>> &mat, int row, int col, vector<vector<int>> &dp)
    {
        if (row < 0 || row >= mat.size() || col >= mat[0].size() || col < 0)
        {
            return 0;
        }
        if (dp[row][col] != -1)
        {
            return dp[row][col];
        }
        int upRight = mat[row][col] + solve(mat, row - 1, col + 1, dp);
        int right = mat[row][col] + solve(mat, row, col + 1, dp);
        int downRight = mat[row][col] + solve(mat, row + 1, col + 1, dp);
        return dp[row][col] = max(upRight, max(right, downRight));
    }
    int maxGold(vector<vector<int>> &mat)
    {
        int n = mat.size(), m = mat[0].size(), ans = 0;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++)
        {
            int curr = solve(mat, i, 0, dp);
            ans = max(ans, curr);
        }
        return ans;
    }
};