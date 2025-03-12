class Solution
{
public:
    int solve(vector<int> &cost, int i, vector<int> &dp)
    {
        if (i >= cost.size())
        {
            return 0;
        }
        if (dp[i] != -1)
        {
            return dp[i];
        }
        int oneStep = cost[i] + solve(cost, i + 1, dp);
        int twoSteps = cost[i] + solve(cost, i + 2, dp);
        return dp[i] = min(oneStep, twoSteps);
    }
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);
        int take = solve(cost, 0, dp1);
        int skip = solve(cost, 1, dp2);
        return min(take, skip);
    }
};