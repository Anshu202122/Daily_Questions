class Solution
{
public:
    int lengthAfterTransformations(string s, int t)
    {
        int m = 1e9 + 7, ans = 0;
        vector<int> mp(26, 0);
        for (char &ch : s)
        {
            mp[ch - 'a']++;
        }
        while (t--)
        {
            vector<int> temp(26, 0);
            for (int i = 0; i < 26; i++)
            {
                char ch = i + 'a';
                int freq = mp[i];
                if (ch != 'z')
                {
                    temp[(ch + 1) - 'a'] = (temp[(ch + 1) - 'a'] + freq) % m;
                }
                else
                {
                    temp['a' - 'a'] = (temp['a' - 'a'] + freq) % m;
                    temp['b' - 'a'] = (temp['b' - 'a'] + freq) % m;
                }
            }
            mp = temp;
        }
        for (int i = 0; i < 26; i++)
        {
            ans = (ans + mp[i]) % m;
        }
        return ans;
    }
};