class Solution
{
public:
    bool isBipartite(unordered_map<int, vector<int>> &adj, int node,
                     vector<int> &colored, int curr)
    {
        colored[node] = curr;
        for (int &a : adj[node])
        {
            if (colored[a] == colored[node])
            {
                return false;
            }
            if (colored[a] == -1)
            {
                if (isBipartite(adj, a, colored, 1 - curr) == false)
                {
                    return false;
                }
            }
        }
        return true;
    }
    int bfs(unordered_map<int, vector<int>> &adj, int node, int n)
    {
        queue<int> q;
        vector<bool> vis(n, false);
        q.push(node);
        vis[node] = true;
        int level = 1;
        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                int curr = q.front();
                q.pop();
                for (int &a : adj[curr])
                {
                    if (vis[a])
                    {
                        continue;
                    }
                    q.push(a);
                    vis[a] = true;
                }
            }
            level++;
        }
        return level - 1;
    }
    int getMax(unordered_map<int, vector<int>> &adj, int node,
               vector<bool> &vis, vector<int> &levels)
    {
        int maxLevel = levels[node];
        vis[node] = true;
        for (int &a : adj[node])
        {
            if (!vis[a])
            {
                maxLevel = max(maxLevel, getMax(adj, a, vis, levels));
            }
        }
        return maxLevel;
    }
    int magnificentSets(int n, vector<vector<int>> &edges)
    {
        unordered_map<int, vector<int>> adj;
        vector<int> colored(n, -1);
        vector<int> levels(n, 0);
        vector<bool> vis(n, false);
        int ans = 0;
        for (auto &e : edges)
        {
            int u = e[0] - 1;
            int v = e[1] - 1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for (int i = 0; i < n; i++)
        {
            if (colored[i] == -1)
            {
                if (!isBipartite(adj, i, colored, 1))
                {
                    return -1;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            levels[i] = bfs(adj, i, n);
        }
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                ans += getMax(adj, i, vis, levels);
            }
        }
        return ans;
    }
};