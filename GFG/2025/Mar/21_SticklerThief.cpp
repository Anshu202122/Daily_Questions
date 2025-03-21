class Solution
{
public:
    int solve(vector<int> &arr, int i, vector<int> &dp)
    {
        if (i >= arr.size())
        {
            return 0;
        }
        if (dp[i] != -1)
        {
            return dp[i];
        }
        int take = arr[i] + solve(arr, i + 2, dp);
        int skip = solve(arr, i + 1, dp);
        return dp[i] = max(take, skip);
    }
    int findMaxSum(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> dp(n, -1);
        return solve(arr, 0, dp);
    }
};