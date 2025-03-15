class Solution
{
public:
    int solve(vector<int> &coins, int sum, int i, vector<vector<int>> &dp)
    {
        if (i == 0)
        {
            if (sum % coins[0] == 0)
            {
                return sum / coins[0];
            }
            return 1e9;
        }
        if (dp[i][sum] != -1)
        {
            return dp[i][sum];
        }
        int take = INT_MAX;
        if (coins[i] <= sum)
        {
            take = 1 + solve(coins, sum - coins[i], i, dp);
        }
        int skip = solve(coins, sum, i - 1, dp);
        return dp[i][sum] = min(take, skip);
    }
    int minCoins(vector<int> &coins, int sum)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        int ans = solve(coins, sum, n - 1, dp);
        if (ans >= 1e9)
        {
            return -1;
        }
        return ans;
    }
};