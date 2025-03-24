class Solution
{
public:
    int solve(vector<int> &arr, int i, int j, vector<vector<int>> &dp)
    {
        if (i + 1 == j)
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int mini = 1e9;
        for (int k = i + 1; k < j; k++)
        {
            int steps = solve(arr, i, k, dp) + solve(arr, k, j, dp) + arr[i] * arr[k] * arr[j];
            if (steps < mini)
            {
                mini = steps;
            }
        }
        return dp[i][j] = mini;
    }
    int matrixMultiplication(vector<int> &arr)
    {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(arr, 0, n - 1, dp);
    }
};