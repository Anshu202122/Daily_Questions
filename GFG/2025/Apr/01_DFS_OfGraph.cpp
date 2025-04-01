class Solution
{
public:
    void solve(vector<vector<int>> &adj, vector<bool> &vis, int i, vector<int> &ans)
    {
        if (i >= adj.size())
        {
            return;
        }
        vis[i] = true;
        ans.push_back(i);
        for (auto &u : adj[i])
        {
            if (!vis[u])
            {
                solve(adj, vis, u, ans);
            }
        }
    }
    vector<int> dfs(vector<vector<int>> &adj)
    {
        int n = adj.size();
        vector<bool> vis(n, false);
        vector<int> ans;
        solve(adj, vis, 0, ans);
        return ans;
    }
};