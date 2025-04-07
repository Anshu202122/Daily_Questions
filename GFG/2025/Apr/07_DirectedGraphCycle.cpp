class Solution
{
public:
    bool solve(vector<vector<int>> &adj, int i, vector<bool> &vis, vector<bool> &s)
    {
        if (s[i])
        {
            return true;
        }
        if (vis[i])
        {
            return false;
        }
        vis[i] = true;
        s[i] = true;
        for (int x : adj[i])
        {
            if (solve(adj, x, vis, s))
            {
                return true;
            }
        }
        s[i] = false;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(V);
        vector<bool> vis(V, false);
        vector<bool> s(V, false);
        for (auto &it : edges)
        {
            adj[it[0]].push_back(it[1]);
        }
        for (int i = 0; i < V; i++)
        {
            if (!vis[i] && solve(adj, i, vis, s))
            {
                return true;
            }
        }
        return false;
    }
};