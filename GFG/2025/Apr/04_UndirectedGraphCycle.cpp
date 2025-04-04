class Solution
{
public:
    bool dfs(int u, int p, vector<vector<int>> &adj, vector<bool> &vis)
    {
        vis[u] = true;
        for (int v : adj[u])
        {
            if (!vis[v] ? dfs(v, u, adj, vis) : v != p)
            {
                return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(V);
        for (auto &edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<bool> vis(V, false);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i] && dfs(i, -1, adj, vis))
            {
                return true;
            }
        }
        return false;
    }
};