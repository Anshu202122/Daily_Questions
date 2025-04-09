class Solution
{
public:
    void solve(vector<vector<int>> &adj, int u, vector<int> &vis, vector<int> &d, vector<int> &low, int &t, int p, vector<int> &ap)
    {
        vis[u] = 1;
        d[u] = low[u] = ++t;
        int c = 0;
        for (int v : adj[u])
        {
            if (!vis[v])
            {
                c++;
                solve(adj, v, vis, d, low, t, u, ap);
                low[u] = min(low[u], low[v]);
                if (p != -1 && low[v] >= d[u])
                {
                    ap[u] = 1;
                }
            }
            else if (v != p)
            {
                low[u] = min(low[u], d[v]);
            }
        }
        if (p == -1 && c > 1)
        {
            ap[u] = 1;
        }
    }
    vector<int> articulationPoints(int V, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(V);
        vector<int> d(V, 0), low(V, 0), vis(V, 0), ap(V, 0);
        vector<int> ans;
        int t = 0;
        for (auto &e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        for (int u = 0; u < V; u++)
        {
            if (!vis[u])
            {
                solve(adj, u, vis, d, low, t, -1, ap);
            }
        }
        for (int i = 0; i < V; i++)
        {
            if (ap[i])
            {
                ans.push_back(i);
            }
        }
        return ans.empty() ? vector<int>{-1} : ans;
    }
};