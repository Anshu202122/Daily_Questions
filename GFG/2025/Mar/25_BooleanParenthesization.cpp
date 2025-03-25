class Solution
{
public:
    int solve(string &s, int i, int j, int isTrue, vector<vector<vector<int>>> &dp)
    {
        if (i > j)
        {
            return 0;
        }
        if (i == j)
        {
            if (isTrue == 1)
            {
                return s[i] == 'T';
            }
            else
            {
                return s[i] == 'F';
            }
        }
        if (dp[i][j][isTrue] != -1)
        {
            return dp[i][j][isTrue];
        }
        int ways = 0;
        for (int k = i + 1; k < j; k += 2)
        {
            int lt = solve(s, i, k - 1, 1, dp);
            int lf = solve(s, i, k - 1, 0, dp);
            int rt = solve(s, k + 1, j, 1, dp);
            int rf = solve(s, k + 1, j, 0, dp);
            if (s[k] == '&')
            {
                if (isTrue == 1)
                {
                    ways += (lt * rt);
                }
                else
                {
                    ways += (lt * rf) + (lf * rt) + (lf * rf);
                }
            }
            else if (s[k] == '|')
            {
                if (isTrue == 1)
                {
                    ways += (lt * rt) + (lt * rf) + (lf * rt);
                }
                else
                {
                    ways += (lf * rf);
                }
            }
            else if (s[k] == '^')
            {
                if (isTrue == 1)
                {
                    ways += (lt * rf) + (lf * rt);
                }
                else
                {
                    ways += (lf * rf) + (lt * rt);
                }
            }
        }
        return dp[i][j][isTrue] = ways;
    }
    int countWays(string &s)
    {
        int n = s.length();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));
        return solve(s, 0, n - 1, 1, dp);
    }
};