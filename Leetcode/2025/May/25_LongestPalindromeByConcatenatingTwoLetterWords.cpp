class Solution
{
public:
    int longestPalindrome(vector<string> &words)
    {
        int n = words.size(), ans = 0;
        unordered_map<string, int> mp;
        for (int i = 0; i < n; i++)
        {
            string str = words[i];
            reverse(str.begin(), str.end());
            if (mp.find(str) == mp.end())
            {
                mp[words[i]]++;
            }
            else
            {
                ans += 4;
                mp[str]--;
                if (mp[str] == 0)
                {
                    mp.erase(str);
                }
            }
        }
        for (auto it : mp)
        {
            string s = it.first;
            int freq = it.second;
            if (s[0] == s[1] && freq > 0)
            {
                ans += (2 * freq);
                break;
            }
        }
        return ans;
    }
};