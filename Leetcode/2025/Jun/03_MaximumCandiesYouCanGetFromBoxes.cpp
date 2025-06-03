class Solution
{
public:
    int dfs(int box, vector<int> &status, vector<int> &candies,
            vector<vector<int>> &keys, vector<vector<int>> &containedBoxes,
            unordered_set<int> &vis, unordered_set<int> &found)
    {
        if (vis.count(box))
        {
            return 0;
        }
        if (status[box] == 0)
        {
            found.insert(box);
            return 0;
        }
        vis.insert(box);
        int ans = candies[box];
        for (int &i : containedBoxes[box])
        {
            ans += dfs(i, status, candies, keys, containedBoxes, vis, found);
        }
        for (int &i : keys[box])
        {
            status[i] = 1;
            if (found.count(i))
            {
                ans +=
                    dfs(i, status, candies, keys, containedBoxes, vis, found);
            }
        }
        return ans;
    }
    int maxCandies(vector<int> &status, vector<int> &candies,
                   vector<vector<int>> &keys,
                   vector<vector<int>> &containedBoxes,
                   vector<int> &initialBoxes)
    {
        int ans = 0;
        unordered_set<int> vis;
        unordered_set<int> found;
        for (int &box : initialBoxes)
        {
            ans += dfs(box, status, candies, keys, containedBoxes, vis, found);
        }
        return ans;
    }
};