class Solution
{
public:
    bool dfs(int u, vector<vector<int>> &g, vector<int> &vis, vector<int> &rec, string &ans)
    {
        vis[u] = rec[u] = 1;
        for (int v = 0; v < 26; v++)
        {
            if (g[u][v])
            {
                if (!vis[v])
                {
                    if (!dfs(v, g, vis, rec, ans))
                    {
                        return false;
                    }
                }
                else if (rec[v])
                {
                    return false;
                }
            }
        }
        ans.push_back(char('a' + u));
        rec[u] = 0;
        return true;
    }
    string findOrder(vector<string> &words)
    {
        vector<vector<int>> g(26, vector<int>(26, 0));
        vector<int> ex(26, 0), vis(26, 0), rec(26, 0);
        string ans = "";
        for (string w : words)
        {
            for (char ch : w)
            {
                ex[ch - 'a'] = 1;
            }
        }
        for (int i = 0; i + 1 < words.size(); i++)
        {
            const string &a = words[i], &b = words[i + 1];
            int n = a.size(), m = b.size(), idx = 0;
            while (idx < n && idx < m && a[idx] == b[idx])
            {
                idx++;
            }
            if (idx != n && idx == m)
            {
                return "";
            }
            if (idx < n && idx < m)
            {
                g[a[idx] - 'a'][b[idx] - 'a'] = 1;
            }
        }
        for (int i = 0; i < 26; i++)
        {
            if (ex[i] && !vis[i])
            {
                if (!dfs(i, g, vis, rec, ans))
                {
                    return "";
                }
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};