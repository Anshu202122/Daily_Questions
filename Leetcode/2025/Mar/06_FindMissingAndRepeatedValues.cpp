class Solution
{
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid)
    {
        int n = grid.size(), num = 1;
        vector<int> ans(2, -1);
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                mp[grid[i][j]]++;
            }
        }
        for (auto &it : mp)
        {
            if (mp.find(num) == mp.end())
            {
                ans[1] = num;
            }
            if (it.second > 1)
            {
                ans[0] = it.first;
            }
            num++;
        }
        if (ans[1] == -1)
        {
            ans[1] = num;
        }
        return ans;
    }
};