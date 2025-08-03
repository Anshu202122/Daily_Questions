class Solution
{
public:
    vector<vector<int>> applyDiff2D(vector<vector<int>> &mat,
                                    vector<vector<int>> &opr)
    {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 0));
        for (auto vec : opr)
        {
            int v = vec[0];
            int r1 = vec[1];
            int c1 = vec[2];
            int r2 = vec[3];
            int c2 = vec[4];
            ans[r1][c1] = ans[r1][c1] + v;
            if (c2 + 1 < m)
            {
                ans[r1][c2 + 1] = ans[r1][c2 + 1] - v;
                if (r2 + 1 < n)
                {
                    ans[r2 + 1][c2 + 1] = ans[r2 + 1][c2 + 1] + v;
                }
            }
            if (r2 + 1 < n)
            {
                ans[r2 + 1][c1] = ans[r2 + 1][c1] - v;
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                ans[i][j] = ans[i][j] + ans[i][j - 1];
            }
        }
        for (int j = 0; j < m; j++)
        {
            for (int i = 1; i < n; i++)
            {
                ans[i][j] = ans[i][j] + ans[i - 1][j];
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                ans[i][j] += mat[i][j];
            }
        }
        return ans;
    }
};