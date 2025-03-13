class Solution
{
public:
    int dp[1001][1001];
    int solve(int i, int w, vector<int> &val, vector<int> &wt)
    {
        if (i == wt.size())
        {
            return 0;
        }
        if (dp[i][w] != -1)
        {
            return dp[i][w];
        }
        int take = 0;
        if (w >= wt[i])
        {
            take = val[i] + solve(i + 1, w - wt[i], val, wt);
        }
        int skip = solve(i + 1, w, val, wt);
        return dp[i][w] = max(take, skip);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt)
    {
        memset(dp, -1, sizeof(dp));
        return solve(0, W, val, wt);
    }
};