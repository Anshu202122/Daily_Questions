class Solution
{
public:
    int solve(string &s, string &r, int i, int j, vector<vector<int>> &dp)
    {
        if (i >= s.length() || j >= r.length())
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int take = 0, skip = 0;
        if (s[i] == r[j])
        {
            take = 1 + solve(s, r, i + 1, j + 1, dp);
        }
        else
        {
            skip = max(solve(s, r, i + 1, j, dp), solve(s, r, i, j + 1, dp));
        }
        return dp[i][j] = max(take, skip);
    }
    int minDeletions(string s)
    {
        int n = s.length();
        string rev = s;
        reverse(rev.begin(), rev.end());
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        int lps = solve(s, rev, 0, 0, dp);
        return n - lps;
    }
};