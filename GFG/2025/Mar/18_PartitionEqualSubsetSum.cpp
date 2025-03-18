class Solution
{
public:
    bool solve(vector<int> &arr, int sum, int i, vector<vector<int>> &dp)
    {
        if (sum == 0)
        {
            return true;
        }
        if (i == arr.size())
        {
            return false;
        }
        if (dp[i][sum] != -1)
        {
            return dp[i][sum];
        }
        bool take = false, skip = false;
        if (arr[i] <= sum)
        {
            take = solve(arr, sum - arr[i], i + 1, dp);
        }
        skip = solve(arr, sum, i + 1, dp);
        return dp[i][sum] = (take || skip);
    }
    bool subset(vector<int> &arr, int sum)
    {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return solve(arr, sum, 0, dp);
    }
    bool equalPartition(vector<int> &arr)
    {
        int ans = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            ans += arr[i];
        }
        if (ans % 2 != 0)
        {
            return false;
        }
        return subset(arr, ans / 2);
    }
};