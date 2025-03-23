class Solution
{
public:
    int solve(string &digits, int i, vector<int> &dp)
    {
        if (i >= digits.size())
        {
            return 1;
        }
        if (digits[i] == '0')
        {
            return 0;
        }
        if (dp[i] != -1)
        {
            return dp[i];
        }
        int takeOne = solve(digits, i + 1, dp);
        int takeTwo = 0;
        if (i != digits.size() - 1 && (digits[i] == '1' || digits[i] == '2' && digits[i + 1] <= '6'))
        {
            takeTwo = solve(digits, i + 2, dp);
        }
        return dp[i] = takeOne + takeTwo;
    }
    int countWays(string &digits)
    {
        int n = digits.size();
        vector<int> dp(n, -1);
        return solve(digits, 0, dp);
    }
};