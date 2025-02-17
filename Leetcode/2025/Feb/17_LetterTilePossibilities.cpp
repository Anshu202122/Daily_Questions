class Solution
{
public:
    void solve(string tiles, string res, set<string> &ans, vector<bool> &vis)
    {
        int n = tiles.size();
        ans.insert(res);
        for (int i = 0; i < n; i++)
        {
            if (vis[i])
            {
                continue;
            }
            vis[i] = true;
            res.push_back(tiles[i]);
            solve(tiles, res, ans, vis);
            vis[i] = false;
            res.pop_back();
        }
    }
    int numTilePossibilities(string tiles)
    {
        int n = tiles.length();
        set<string> ans;
        string res = "";
        vector<bool> vis(n, false);
        solve(tiles, res, ans, vis);
        return ans.size() - 1;
    }
};