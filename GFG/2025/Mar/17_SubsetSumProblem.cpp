class Solution
{
public:
    bool solve(vector<int> &arr, int sum, int i, vector<vector<int>> &dp)
    {
        if (i >= arr.size())
        {
            if (sum == 0)
            {
                return true;
            }
            return false;
        }
        if (dp[i][sum] != -1)
        {
            return dp[i][sum];
        }
        bool take = false;
        if (arr[i] <= sum)
        {
            take = solve(arr, sum - arr[i], i + 1, dp);
        }
        bool skip = solve(arr, sum, i + 1, dp);
        return dp[i][sum] = take || skip;
    }
    bool isSubsetSum(vector<int> &arr, int sum)
    {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return solve(arr, sum, 0, dp);
    }
};