class Solution
{
public:
    bool solve(vector<vector<char>> &mat, string &word, int i, int j, int idx, vector<vector<bool>> &vis)
    {
        int m = mat.size();
        int n = mat[0].size();
        if (idx == word.length())
        {
            return true;
        }
        if (i < 0 || j < 0 || i >= m || j >= n || vis[i][j] || mat[i][j] != word[idx])
        {
            return false;
        }
        vis[i][j] = true;
        if (solve(mat, word, i - 1, j, idx + 1, vis) || solve(mat, word, i + 1, j, idx + 1, vis) ||
            solve(mat, word, i, j - 1, idx + 1, vis) || solve(mat, word, i, j + 1, idx + 1, vis))
        {
            return true;
        }
        vis[i][j] = false;
        return false;
    }
    bool isWordExist(vector<vector<char>> &mat, string &word)
    {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == word[0])
                {
                    if (solve(mat, word, i, j, 0, vis))
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};