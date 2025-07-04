class Solution
{
public:
    int maxSum(vector<int> &arr)
    {
        int n = arr.size(), ans = 0;
        for (int i = 1; i < n; i++)
        {
            ans = max(ans, arr[i] + arr[i - 1]);
        }
        return ans;
    }
};