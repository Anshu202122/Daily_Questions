class Solution
{
public:
    int solve(vector<int> &prices, int k, int i, bool canBuy, vector<vector<vector<int>>> &dp)
    {
        if (i == prices.size() || k == 0)
        {
            return 0;
        }
        if (dp[i][k][canBuy] != -1)
        {
            return dp[i][k][canBuy];
        }
        int take = 0, skip = 0;
        if (canBuy)
        {
            take = -prices[i] + solve(prices, k, i + 1, false, dp);
            skip = solve(prices, k, i + 1, true, dp);
        }
        else
        {
            take = prices[i] + solve(prices, k - 1, i + 1, true, dp);
            skip = solve(prices, k, i + 1, false, dp);
        }
        return dp[i][k][canBuy] = max(take, skip);
    }
    int maxProfit(vector<int> &prices, int k)
    {
        int n = prices.size();
        bool canBuy = true;
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k + 1, vector<int>(2, -1)));
        return solve(prices, k, 0, canBuy, dp);
    }
};