class Solution
{
public:
    int longestStringChain(vector<string> &words)
    {
        int n = words.size();
        sort(words.begin(), words.end(), [](const string &a, const string &b)
             { return a.size() < b.size(); });
        unordered_map<string, int> mp;
        int ans = 1;
        for (string &s : words)
        {
            int len = 1;
            for (int i = 0; i < s.size(); i++)
            {
                string str = s.substr(0, i) + s.substr(i + 1);
                if (mp.find(str) != mp.end())
                {
                    len = max(len, mp[str] + 1);
                }
            }
            mp[s] = len;
            ans = max(ans, len);
        }
        return ans;
    }
};