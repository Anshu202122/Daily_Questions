class Solution
{
public:
    void dfs(vector<vector<int>> &adj, int i, vector<bool> &vis, stack<int> &s)
    {
        vis[i] = true;
        for (int u : adj[i])
        {
            if (!vis[u])
            {
                dfs(adj, u, vis, s);
            }
        }
        s.push(i);
    }
    vector<int> topoSort(int V, vector<vector<int>> &edges)
    {
        stack<int> s;
        vector<vector<int>> adj(V);
        vector<bool> vis(V, false);
        vector<int> ans;
        for (auto &edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
        }
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(adj, i, vis, s);
            }
        }
        while (!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};