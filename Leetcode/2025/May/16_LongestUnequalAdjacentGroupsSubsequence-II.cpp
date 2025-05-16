class Solution
{
public:
    bool check(string &s1, string &s2)
    {
        int diff = 0;
        for (int i = 0; i < s1.length(); i++)
        {
            if (s1[i] != s2[i])
            {
                diff++;
            }
            if (diff > 1)
            {
                return false;
            }
        }
        return diff == 1;
    }
    vector<string> getWordsInLongestSubsequence(vector<string> &words, vector<int> &groups)
    {
        int n = words.size(), sub = 1, idx = 0;
        vector<string> ans;
        vector<int> dp(n, 1);
        vector<int> p(n, -1);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= i - 1; j++)
            {
                if (groups[j] != groups[i] && words[i].length() == words[j].length() && check(words[i], words[j]))
                {
                    if (dp[j] + 1 > dp[i])
                    {
                        dp[i] = dp[j] + 1;
                        p[i] = j;
                        if (sub < dp[i])
                        {
                            sub = dp[i];
                            idx = i;
                        }
                    }
                }
            }
        }
        while (idx != -1)
        {
            ans.push_back(words[idx]);
            idx = p[idx];
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};