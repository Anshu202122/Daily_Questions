class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        int n = s.length();
        int ans = 0;
        vector<int> arr(3, 0);
        int i = 0, j = 0;
        while (j < n)
        {
            char ch = s[j];
            arr[ch - 'a']++;
            while (arr[0] > 0 && arr[1] > 0 && arr[2] > 0)
            {
                ans += n - j;
                arr[s[i] - 'a']--;
                i++;
            }
            j++;
        }
        return ans;
    }
};