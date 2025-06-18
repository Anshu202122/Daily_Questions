class Solution
{
public:
    bool isPal(string &str, int s, int e)
    {
        while (s <= e)
        {
            if (str[s] != str[e])
            {
                return false;
            }
            s++;
            e--;
        }
        return true;
    }
    void solve(string &s, int idx, vector<string> &temp, vector<vector<string>> &ans)
    {
        if (idx == s.length())
        {
            ans.push_back(temp);
            return;
        }
        for (int i = idx; i < s.length(); i++)
        {
            if (isPal(s, idx, i))
            {
                string str = s.substr(idx, i - idx + 1);
                temp.push_back(str);
                solve(s, i + 1, temp, ans);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> palinParts(string &s)
    {
        vector<string> temp;
        vector<vector<string>> ans;
        solve(s, 0, temp, ans);
        return ans;
    }
};