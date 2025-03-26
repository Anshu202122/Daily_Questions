class Solution
{
public:
    bool solve(string &s, set<string> &st, int i, vector<int> &dp)
    {
        if (i >= s.length())
        {
            return 1;
        }
        if (dp[i] != -1)
        {
            return dp[i];
        }
        string temp = "";
        for (int j = i; j < s.length(); j++)
        {
            temp += s[j];
            if (st.find(temp) != st.end())
            {
                if (solve(s, st, j + 1, dp))
                {
                    return dp[i] = 1;
                }
            }
        }
        return dp[i] = 0;
    }
    bool wordBreak(string &s, vector<string> &dictionary)
    {
        int n = s.length();
        set<string> st;
        vector<int> dp(n, -1);
        for (auto &it : dictionary)
        {
            st.insert(it);
        }
        return solve(s, st, 0, dp);
    }
};