class Solution
{
public:
    int mod = 1e9 + 7;
    int solve(int n, int num, int x, vector<vector<int>> &dp)
    {
        if (n == 0)
        {
            return 1;
        }
        if (n < 0)
        {
            return 0;
        }
        int p = pow(num, x);
        if (p > n)
        {
            return 0;
        }
        if (dp[n][num] != -1)
        {
            return dp[n][num];
        }
        int take = solve(n - p, num + 1, x, dp);
        int skip = solve(n, num + 1, x, dp);
        return dp[n][num] = (take + skip) % mod;
    }
    int numberOfWays(int n, int x)
    {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return solve(n, 1, x, dp);
    }
};