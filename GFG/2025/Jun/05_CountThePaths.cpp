class Solution
{
public:
    int dfs(vector<vector<int>> &adj, int u, int dest, vector<vector<int>> &dp)
    {
        if (u == dest)
        {
            return 1;
        }
        if (dp[u][dest] != -1)
        {
            return dp[u][dest];
        }
        int ans = 0;
        for (int v : adj[u])
        {
            ans += dfs(adj, v, dest, dp);
        }
        return dp[u][dest] = ans;
    }
    int countPaths(vector<vector<int>> &edges, int V, int src, int dest)
    {
        vector<vector<int>> adj(V);
        vector<vector<int>> dp(V, vector<int>(V, -1));
        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }
        return dfs(adj, src, dest, dp);
    }
};