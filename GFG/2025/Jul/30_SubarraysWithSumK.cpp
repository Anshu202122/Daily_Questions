class Solution
{
public:
    int cntSubarrays(vector<int> &arr, int k)
    {
        int n = arr.size(), sum = 0, ans = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            if (sum == k)
            {
                ans++;
            }
            if (mp.find(sum - k) != mp.end())
            {
                ans += mp[sum - k];
            }
            mp[sum]++;
        }
        return ans;
    }
};