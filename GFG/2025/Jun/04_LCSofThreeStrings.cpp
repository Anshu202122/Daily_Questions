class Solution
{
public:
    int solve(int i, int j, int k, string &s1, string &s2, string &s3, vector<vector<vector<int>>> &dp)
    {
        if (i >= s1.length() || j >= s2.length() || k >= s3.length())
        {
            return 0;
        }
        if (dp[i][j][k] != -1)
        {
            return dp[i][j][k];
        }
        if (s1[i] == s2[j] && s1[i] == s3[k])
        {
            return 1 + solve(i + 1, j + 1, k + 1, s1, s2, s3, dp);
        }
        return dp[i][j][k] = max(solve(i + 1, j, k, s1, s2, s3, dp), max(solve(i, j + 1, k, s1, s2, s3, dp), solve(i, j, k + 1, s1, s2, s3, dp)));
    }
    int lcsOf3(string &s1, string &s2, string &s3)
    {
        int n1 = s1.length(), n2 = s2.length(), n3 = s3.length();
        vector<vector<vector<int>>> dp(n1, vector<vector<int>>(n2, vector<int>(n3, -1)));
        return solve(0, 0, 0, s1, s2, s3, dp);
    }
};