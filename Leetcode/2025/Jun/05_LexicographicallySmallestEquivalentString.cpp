class Solution
{
public:
    char solve(vector<vector<char>> &adj, char ch, vector<int> &vis)
    {
        vis[ch - 'a'] = 1;
        char minCh = ch;
        for (char &v : adj[ch - 'a'])
        {
            if (vis[v - 'a'] == 0)
            {
                minCh = min(minCh, solve(adj, v, vis));
            }
        }
        return minCh;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr)
    {
        int n = s1.length(), m = baseStr.length();
        vector<vector<char>> adj(26);
        string ans = "";
        for (int i = 0; i < n; i++)
        {
            char u = s1[i];
            char v = s2[i];
            adj[u - 'a'].push_back(v);
            adj[v - 'a'].push_back(u);
        }
        for (int i = 0; i < m; i++)
        {
            char ch = baseStr[i];
            vector<int> vis(26, 0);
            char minCh = solve(adj, ch, vis);
            ans += minCh;
        }
        return ans;
    }
};