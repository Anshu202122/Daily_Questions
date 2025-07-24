class Solution
{
public:
    void dfs(int u, int p, vector<int> &subXor, vector<int> &inTime,
             vector<int> &outTime, vector<int> &nums, vector<vector<int>> &adj,
             int &time)
    {
        subXor[u] = nums[u];
        inTime[u] = time;
        time++;
        for (int v : adj[u])
        {
            if (v != p)
            {
                dfs(v, u, subXor, inTime, outTime, nums, adj, time);
                subXor[u] ^= subXor[v];
            }
        }
        outTime[u] = time;
        time++;
    }
    bool isAncestor(int u, int v, vector<int> &inTime, vector<int> &outTime)
    {
        return inTime[v] > inTime[u] && outTime[v] < outTime[u];
    }
    int getScore(int a, int b, int c)
    {
        int maxXor = max({a, b, c});
        int minXor = min({a, b, c});
        return maxXor - minXor;
    }
    int minimumScore(vector<int> &nums, vector<vector<int>> &edges)
    {
        int n = nums.size(), time = 0, ans = INT_MAX;
        vector<vector<int>> adj(n);
        vector<int> subXor(n, 0);
        vector<int> inTime(n, 0);
        vector<int> outTime(n, 0);
        for (auto &e : edges)
        {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(0, -1, subXor, inTime, outTime, nums, adj, time);
        for (int i = 1; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int xor1, xor2, xor3;
                if (isAncestor(i, j, inTime, outTime))
                {
                    xor1 = subXor[j];
                    xor2 = subXor[i] ^ xor1;
                    xor3 = subXor[0] ^ xor1 ^ xor2;
                }
                else if (isAncestor(j, i, inTime, outTime))
                {
                    xor1 = subXor[i];
                    xor2 = subXor[j] ^ xor1;
                    xor3 = subXor[0] ^ xor1 ^ xor2;
                }
                else
                {
                    xor1 = subXor[i];
                    xor2 = subXor[j];
                    xor3 = subXor[0] ^ xor1 ^ xor2;
                }
                ans = min(ans, getScore(xor1, xor2, xor3));
            }
        }
        return ans;
    }
};