class Solution
{
public:
    bool isPossible(vector<vector<int>> &mat, int i, int j, int k, vector<int> &row, vector<int> &col, vector<int> &vec)
    {
        if ((row[i] & (1 << k)) || (col[j] & (1 << k)) || vec[i / 3 * 3 + j / 3] & (1 << k))
        {
            return false;
        }
        return true;
    }
    bool solve(vector<vector<int>> &mat, int i, int j, vector<int> &row, vector<int> &col, vector<int> &vec)
    {
        int n = mat.size();
        if (i == n - 1 && j == n)
        {
            return true;
        }
        if (j == n)
        {
            i++;
            j = 0;
        }
        if (mat[i][j] != 0)
        {
            return solve(mat, i, j + 1, row, col, vec);
        }
        for (int k = 1; k <= n; k++)
        {
            if (isPossible(mat, i, j, k, row, col, vec))
            {
                mat[i][j] = k;
                row[i] |= (1 << k);
                col[j] |= (1 << k);
                vec[(i / 3) * 3 + j / 3] |= (1 << k);
                if (solve(mat, i, j + 1, row, col, vec))
                {
                    return true;
                }
                mat[i][j] = 0;
                row[i] &= ~(1 << k);
                col[j] &= ~(1 << k);
                vec[(i / 3) * 3 + j / 3] &= ~(1 << k);
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<int>> &mat)
    {
        int n = mat.size();
        vector<int> row(n, 0);
        vector<int> col(n, 0);
        vector<int> vec(n, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] != 0)
                {
                    row[i] |= (1 << mat[i][j]);
                    col[j] |= (1 << mat[i][j]);
                    vec[(i / 3) * 3 + j / 3] |= (1 << mat[i][j]);
                }
            }
        }
        solve(mat, 0, 0, row, col, vec);
    }
};