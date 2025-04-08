class Solution
{
public:
    void dfs(int n, vector<int> adj[], vector<int> &vis, int c, int d)
    {
        vis[n] = true;
        for (auto it : adj[n])
        {
            if (!vis[it] && !(n == c && it == d))
            {
                dfs(it, adj, vis, c, d);
            }
        }
    }
    bool isBridge(int V, vector<vector<int>> &edges, int c, int d)
    {
        vector<int> adj[V];
        vector<int> vis(V, 0);
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(c, adj, vis, c, d);
        if (vis[d])
        {
            return false;
        }
        return true;
    }
};