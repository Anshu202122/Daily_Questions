class Solution
{
public:
    vector<vector<int>> dir{{1, 0}, {-1, 0}, {0, -1}, {0, 1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
    void solve(vector<vector<char>> &grid, int i, int j)
    {
        int n = grid.size(), m = grid[0].size();
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 'W')
        {
            return;
        }
        grid[i][j] = 'W';
        for (auto &it : dir)
        {
            int x = i + it[0];
            int y = j + it[1];
            solve(grid, x, y);
        }
    }
    int countIslands(vector<vector<char>> &grid)
    {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 'L')
                {
                    solve(grid, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};