class Solution
{
public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src)
    {
        vector<vector<vector<int>>> adj(V);
        for (auto &e : edges)
        {
            int u = e[0];
            int v = e[1];
            int w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> ans(V, INT_MAX);
        ans[src] = 0;
        pq.push({0, src});
        while (!pq.empty())
        {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            for (auto &v : adj[u])
            {
                int node = v[0];
                int dist = v[1];
                if (d + dist < ans[node])
                {
                    ans[node] = d + dist;
                    pq.push({d + dist, node});
                }
            }
        }
        return ans;
    }
};