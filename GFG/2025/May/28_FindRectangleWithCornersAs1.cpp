class Solution
{
public:
    bool ValidCorner(vector<vector<int>> &mat)
    {
        int m = mat.size(), n = mat[0].size();
        unordered_map<int, set<int>> mp;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    if (mat[i][j] == 1 && mat[i][k] == 1)
                    {
                        if (mp.find(j) != mp.end() && mp[j].find(k) != mp[j].end())
                        {
                            return true;
                        }
                        else
                        {
                            mp[j].insert(k);
                        }
                    }
                }
            }
        }
        return false;
    }
};