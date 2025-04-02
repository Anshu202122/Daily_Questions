class Solution
{
public:
    vector<int> bfs(vector<vector<int>> &adj)
    {
        int n = adj.size();
        vector<int> ans;
        vector<bool> vis(n, false);
        queue<int> q;
        q.push(0);
        vis[0] = true;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            ans.push_back(u);
            for (auto &v : adj[u])
            {
                if (!vis[v])
                {
                    q.push(v);
                    vis[v] = true;
                }
            }
        }
        return ans;
    }
};