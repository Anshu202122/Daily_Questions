class Solution
{
public:
    int substrCount(string &s, int k)
    {
        int n = s.length(), ans = 0, i = 0, j = 0;
        unordered_map<char, int> mp;
        while (j < n)
        {
            while (j < i + k)
            {
                mp[s[j]]++;
                j++;
            }
            if (mp.size() == k - 1)
            {
                ans++;
            }
            mp[s[i]]--;
            if (mp[s[i]] == 0)
            {
                mp.erase(s[i]);
            }
            i++;
        }
        return ans;
    }
};