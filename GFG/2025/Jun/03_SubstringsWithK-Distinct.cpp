class Solution
{
public:
    int solve(string &s, int k)
    {
        int n = s.length(), ans = 0, cnt = 0, i = 0;
        vector<int> freq(26, 0);
        for (int j = 0; j < n; j++)
        {
            freq[s[j] - 'a']++;
            if (freq[s[j] - 'a'] == 1)
            {
                cnt++;
            }
            while (cnt > k)
            {
                freq[s[i] - 'a']--;
                if (freq[s[i] - 'a'] == 0)
                {
                    cnt--;
                }
                i++;
            }
            ans += j - i + 1;
        }
        return ans;
    }
    int countSubstr(string &s, int k)
    {
        return solve(s, k) - solve(s, k - 1);
    }
};