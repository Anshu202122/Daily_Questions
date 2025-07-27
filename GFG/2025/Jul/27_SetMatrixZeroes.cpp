class Solution
{
public:
    void setMatrixZeroes(vector<vector<int>> &mat)
    {
        int n = mat.size(), m = mat[0].size();
        vector<pair<int, int>> pos;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 0)
                {
                    pos.push_back({i, j});
                }
            }
        }
        for (auto &p : pos)
        {
            int x = p.first, y = p.second;
            for (int i = 0; i < m; i++)
            {
                mat[x][i] = 0;
            }
            for (int j = 0; j < n; j++)
            {
                mat[j][y] = 0;
            }
        }
    }
};