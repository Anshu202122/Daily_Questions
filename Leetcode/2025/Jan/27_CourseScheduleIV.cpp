class Solution
{
public:
    bool dfs(unordered_map<int, vector<int>> &adj, int x, int y, vector<bool> &vis)
    {
        vis[x] = true;
        bool canReach = false;
        if (x == y)
        {
            return true;
        }
        for (auto &a : adj[x])
        {
            if (!vis[a])
            {
                canReach = canReach || dfs(adj, a, y, vis);
            }
        }
        return canReach;
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>> &prerequisites, vector<vector<int>> &queries)
    {
        unordered_map<int, vector<int>> adj;
        int size = queries.size();
        vector<bool> ans(size);
        for (auto &e : prerequisites)
        {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
        }
        for (int i = 0; i < size; i++)
        {
            int u = queries[i][0];
            int v = queries[i][1];
            vector<bool> vis(numCourses, false);
            ans[i] = dfs(adj, u, v, vis);
        }
        return ans;
    }
};