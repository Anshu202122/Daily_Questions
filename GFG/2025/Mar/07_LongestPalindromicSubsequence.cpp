class Solution
{
public:
    int solve(int i, int j, string &s, vector<vector<int>> &dp)
    {
        if (i < 0 || j >= s.length())
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int ans;
        if (s[i] == s[j])
        {
            ans = 1 + solve(i - 1, j + 1, s, dp);
        }
        else
        {
            ans = max(solve(i - 1, j, s, dp), solve(i, j + 1, s, dp));
        }
        dp[i][j] = ans;
        return ans;
    }
    int longestPalinSubseq(string &s)
    {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(n - 1, 0, s, dp);
    }
};