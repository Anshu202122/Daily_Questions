class Solution
{
public:
    int solve(int n, vector<vector<vector<int>>> &adj, int src, int des)
    {
        vector<int> dist(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        dist[src] = 0;
        pq.push({0, src});
        while (!pq.empty())
        {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            if (d > dist[u])
            {
                continue;
            }
            for (auto &e : adj[u])
            {
                int v = e[0];
                int w = e[1];
                if ((u == src && v == des) || (u == des && v == src))
                {
                    continue;
                }
                if (dist[v] > dist[u] + w)
                {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist[des];
    }
    int findMinCycle(int V, vector<vector<int>> &edges)
    {
        vector<vector<vector<int>>> adj(V);
        int ans = INT_MAX;
        for (auto &e : edges)
        {
            int u = e[0];
            int v = e[1];
            int w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        for (auto &e : edges)
        {
            int u = e[0];
            int v = e[1];
            int w = e[2];
            int d = solve(V, adj, u, v);
            if (d != INT_MAX)
            {
                ans = min(ans, d + w);
            }
        }
        return ans;
    }
};