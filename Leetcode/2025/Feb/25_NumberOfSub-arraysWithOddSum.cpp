class Solution
{
public:
    int numOfSubarrays(vector<int> &arr)
    {
        int n = arr.size(), ans = 0;
        int mod = 1e9 + 7, even = 1, odd = 0;
        vector<int> preSum(n);
        preSum[0] = arr[0];
        for (int i = 1; i < n; i++)
        {
            preSum[i] = arr[i] + preSum[i - 1];
        }
        for (int i = 0; i < n; i++)
        {
            if (preSum[i] % 2 == 0)
            {
                ans = (ans + odd) % mod;
                even++;
            }
            else
            {
                ans = (ans + even) % mod;
                odd++;
            }
        }
        return ans % mod;
    }
};