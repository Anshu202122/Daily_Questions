class Solution
{
public:
    int largestPathValue(string colors, vector<vector<int>> &edges)
    {
        int n = colors.size(), ans = 0, count = 0;
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        queue<int> q;
        vector<vector<int>> arr(n, vector<int>(26, 0));
        for (auto &e : edges)
        {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
                arr[i][colors[i] - 'a'] = 1;
            }
        }
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            count++;
            ans = max(ans, arr[u][colors[u] - 'a']);
            for (int &v : adj[u])
            {
                for (int i = 0; i < 26; i++)
                {
                    arr[v][i] =
                        max(arr[v][i], arr[u][i] + (colors[v] - 'a' == i));
                }
                indegree[v]--;
                if (indegree[v] == 0)
                {
                    q.push(v);
                }
            }
        }
        if (count < n)
        {
            return -1;
        }
        return ans;
    }
};