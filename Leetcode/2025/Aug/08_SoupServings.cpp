class Solution
{
public:
    vector<pair<int, int>> prob = {{100, 0}, {75, 25}, {50, 50}, {25, 75}};
    double solve(int a, int b, vector<vector<double>> &dp)
    {
        if (a <= 0 && b <= 0)
        {
            return 0.5;
        }
        if (a <= 0)
        {
            return 1.0;
        }
        if (b <= 0)
        {
            return 0.0;
        }
        if (dp[a][b] != -1.0)
        {
            return dp[a][b];
        }
        double p = 0.0;
        for (auto it : prob)
        {
            int a_taken = it.first;
            int b_taken = it.second;
            p += solve(a - a_taken, b - b_taken, dp);
        }
        return dp[a][b] = 0.25 * p;
    }
    double soupServings(int n)
    {
        if (n >= 5000)
        {
            return 1;
        }
        vector<vector<double>> dp(n + 1, vector<double>(n + 1, -1.0));
        return solve(n, n, dp);
    }
};