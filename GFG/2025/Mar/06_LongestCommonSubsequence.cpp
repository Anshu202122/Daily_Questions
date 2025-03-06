class Solution
{
public:
    int solve(int i, int j, string &s1, string &s2, vector<vector<int>> &dp)
    {
        if (i >= s1.length() || j >= s2.length())
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        if (s1[i] == s2[j])
        {
            return dp[i][j] = 1 + solve(i + 1, j + 1, s1, s2, dp);
        }
        return dp[i][j] = max(solve(i, j + 1, s1, s2, dp), solve(i + 1, j, s1, s2, dp));
    }
    int lcs(string &s1, string &s2)
    {
        int n = s1.length();
        int m = s2.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(0, 0, s1, s2, dp);
    }
};