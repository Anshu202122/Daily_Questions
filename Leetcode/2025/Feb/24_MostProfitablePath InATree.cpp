class Solution
{
public:
    unordered_map<int, vector<int>> adj;
    unordered_map<int, int> mp;
    int ans;
    bool dfsBob(int curr, int t, vector<bool> &vis)
    {
        vis[curr] = true;
        mp[curr] = t;
        if (curr == 0)
        {
            return true;
        }
        for (auto &n : adj[curr])
        {
            if (!vis[n])
            {
                if (dfsBob(n, t + 1, vis))
                {
                    return true;
                }
            }
        }
        mp.erase(curr);
        return false;
    }
    void dfs(int curr, int t, int income, vector<bool> &vis,
             vector<int> &amount)
    {
        vis[curr] = true;
        if (mp.find(curr) == mp.end() || t < mp[curr])
        {
            income += amount[curr];
        }
        else if (t == mp[curr])
        {
            income += amount[curr] / 2;
        }
        if (adj[curr].size() == 1 && curr != 0)
        {
            ans = max(ans, income);
        }
        for (int &n : adj[curr])
        {
            if (!vis[n])
            {
                dfs(n, t + 1, income, vis, amount);
            }
        }
    }
    int mostProfitablePath(vector<vector<int>> &edges, int bob,
                           vector<int> &amount)
    {
        int n = amount.size();
        ans = INT_MIN;
        int time = 0, income = 0;
        vector<bool> vis(n, false);
        for (vector<int> e : edges)
        {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfsBob(bob, time, vis);
        vis.assign(n, false);
        dfs(0, 0, income, vis, amount);
        return ans;
    }
};