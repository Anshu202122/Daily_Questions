class Solution
{
public:
    int longestSubarray(vector<int> &arr, int k)
    {
        int n = arr.size(), ans = 0, sum = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > k)
            {
                sum += 1;
            }
            else
            {
                sum -= 1;
            }
            if (sum > 0)
            {
                ans = i + 1;
            }
            if (mp.find(sum - 1) != mp.end())
            {
                ans = max(ans, i - mp[sum - 1]);
            }
            if (mp.find(sum) == mp.end())
            {
                mp[sum] = i;
            }
        }
        return ans;
    }
};