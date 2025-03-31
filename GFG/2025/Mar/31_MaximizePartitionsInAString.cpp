class Solution
{
public:
    int maxPartitions(string &str)
    {
        int n = str.length();
        int i = 0, j = 0, k = 0, c = 0, r = 0;
        unordered_map<char, int> mp;
        for (i = n - 1; i > 0; i--)
        {
            if (mp[str[i]] == 0)
            {
                mp[str[i]] = i;
            }
        }
        i = 0;
        k = mp[str[i]];
        for (int i = 0; i < str.length(); i++)
        {
            if (i <= k)
            {
                c += 1;
                k = max(k, mp[str[i]]);
            }
            else
            {
                r += 1;
                c = 1;
                k = max(k, mp[str[i]]);
            }
        }
        if (c != 0)
        {
            r += 1;
        }
        return r;
    }
};