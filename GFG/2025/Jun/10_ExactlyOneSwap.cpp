class Solution
{
public:
    int countStrings(string &s)
    {
        int n = s.length(), ans = 0;
        vector<int> arr(26, 0);
        for (int i = 0; i < n; i++)
        {
            ans += (i - arr[s[i] - 'a']);
            arr[s[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++)
        {
            if (arr[i] > 1)
            {
                ans++;
                break;
            }
        }
        return ans;
    }
};