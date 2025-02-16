class Solution
{
public:
    bool solve(int n, int idx, vector<int> &ans, vector<bool> &vis)
    {
        if (idx >= ans.size())
        {
            return true;
        }
        if (ans[idx] != -1)
        {
            return solve(n, idx + 1, ans, vis);
        }
        for (int i = n; i > 0; i--)
        {
            if (vis[i])
            {
                continue;
            }
            vis[i] = true;
            ans[idx] = i;
            if (i == 1)
            {
                if (solve(n, idx + 1, ans, vis))
                {
                    return true;
                }
            }
            else
            {
                int j = idx + ans[idx];
                if (j < ans.size() && ans[j] == -1)
                {
                    ans[j] = i;
                    if (solve(n, idx + 1, ans, vis))
                    {
                        return true;
                    }
                    ans[j] = -1;
                }
            }
            vis[i] = false;
            ans[idx] = -1;
        }
        return false;
    }
    vector<int> constructDistancedSequence(int n)
    {
        vector<int> ans(2 * n - 1, -1);
        vector<bool> vis(n + 1, false);
        solve(n, 0, ans, vis);
        return ans;
    }
};