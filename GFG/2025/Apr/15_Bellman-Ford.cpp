class Solution
{
public:
    vector<int> bellmanFord(int V, vector<vector<int>> &edges, int src)
    {
        vector<int> ans(V, 1e8);
        ans[src] = 0;
        for (int i = 0; i < V; i++)
        {
            for (auto &e : edges)
            {
                int u = e[0];
                int v = e[1];
                int w = e[2];
                if (ans[u] != 1e8 && ans[u] + w < ans[v])
                {
                    if (i == V - 1)
                    {
                        return {-1};
                    }
                    ans[v] = ans[u] + w;
                }
            }
        }
        return ans;
    }
};