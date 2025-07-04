class Solution
{
public:
    int countAtMostK(vector<int> &arr, int k)
    {
        int n = arr.size(), ans = 0, i = 0, j = 0;
        unordered_map<int, int> mp;
        while (j < n)
        {
            mp[arr[j]]++;
            if (mp[arr[j]] == 1)
            {
                k--;
            }
            while (k < 0)
            {
                mp[arr[i]]--;
                if (mp[arr[i]] == 0)
                {
                    k++;
                }
                i++;
            }
            ans += (j - i + 1);
            j++;
        }
        return ans;
    }
};