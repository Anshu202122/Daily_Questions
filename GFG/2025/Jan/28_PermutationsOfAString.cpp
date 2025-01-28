class Solution
{
public:
    void solve(string &s, set<string> &st, int idx)
    {
        if (idx == s.length())
        {
            st.insert(s);
            return;
        }
        for (int i = idx; i < s.length(); i++)
        {
            swap(s[idx], s[i]);
            solve(s, st, idx + 1);
            swap(s[idx], s[i]);
        }
    }
    vector<string> findPermutation(string &s)
    {
        set<string> st;
        vector<string> ans;
        solve(s, st, 0);
        for (auto &str : st)
        {
            ans.push_back(str);
        }
        return ans;
    }
};