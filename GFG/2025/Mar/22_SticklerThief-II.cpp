class Solution
{
public:
    int solve1(vector<int> &arr, int i, vector<int> &dp)
    {
        if (i >= arr.size() - 1)
        {
            return 0;
        }
        if (dp[i] != -1)
        {
            return dp[i];
        }
        int take = arr[i] + solve1(arr, i + 2, dp);
        int skip = solve1(arr, i + 1, dp);
        return dp[i] = max(take, skip);
    }
    int solve2(vector<int> &arr, int i, vector<int> &dp)
    {
        if (i >= arr.size())
        {
            return 0;
        }
        if (dp[i] != -1)
        {
            return dp[i];
        }
        int take = arr[i] + solve2(arr, i + 2, dp);
        int skip = solve2(arr, i + 1, dp);
        return dp[i] = max(take, skip);
    }
    int maxValue(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);
        int take = solve1(arr, 0, dp1);
        int skip = solve2(arr, 1, dp2);
        return max(take, skip);
    }
};