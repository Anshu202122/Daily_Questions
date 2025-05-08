class Solution
{
public:
    int findMissing(vector<int> &arr)
    {
        int n = arr.size();
        int diff = (arr[1] - arr[0] == arr[n - 1] - arr[n - 2]) ? arr[1] - arr[0] : ((arr[1] - arr[0] == (arr[n - 1] - arr[0]) / n) ? arr[1] - arr[0] : arr[n - 1] - arr[n - 2]);
        if (diff == 0)
            return arr[0];
        long long s = (2LL * arr[0] + n * diff) * (n + 1) / 2;
        int sum = 0;
        for (int i = 0; i <= n - 1; i++)
        {
            sum = sum + arr[i];
        }
        return s - sum;
    }
};