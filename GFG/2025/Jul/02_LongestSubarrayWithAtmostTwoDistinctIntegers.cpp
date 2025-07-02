class Solution
{
public:
    int totalElements(vector<int> &arr)
    {
        int n = arr.size(), i = 0, j = 0, ans = 0;
        unordered_map<int, int> mp;
        while (j < n)
        {
            while (j < n && mp.size() < 3)
            {
                mp[arr[j]]++;
                j++;
            }
            if (mp.size() == 3)
            {
                ans = max(ans, j - i - 1);
            }
            else
            {
                ans = max(ans, j - i);
            }
            mp[arr[i]]--;
            if (mp[arr[i]] == 0)
            {
                mp.erase(arr[i]);
            }
            i++;
        }
        return ans;
    }
};