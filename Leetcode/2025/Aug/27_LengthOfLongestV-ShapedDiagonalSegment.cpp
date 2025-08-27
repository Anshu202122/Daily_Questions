class Solution
{
public:
    vector<vector<int>> dir = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
    int n, m;
    int solve(vector<vector<int>> &grid, int i, int j, int d, bool canTurn,
              int val, vector<vector<vector<vector<int>>>> &dp)
    {
        int new_i = i + dir[d][0];
        int new_j = j + dir[d][1];
        if (new_i < 0 || new_i >= n || new_j < 0 || new_j >= m ||
            grid[new_i][new_j] != val)
        {
            return 0;
        }
        if (dp[new_i][new_j][d][canTurn] != -1)
        {
            return dp[new_i][new_j][d][canTurn];
        }
        int length = 0;
        length = max(length, 1 + solve(grid, new_i, new_j, d, canTurn,
                                       val == 2 ? 0 : 2, dp));
        if (canTurn)
        {
            length = max(length, 1 + solve(grid, new_i, new_j, (d + 1) % 4,
                                           !canTurn, val == 2 ? 0 : 2, dp));
        }
        return dp[new_i][new_j][d][canTurn] = length;
    }
    int lenOfVDiagonal(vector<vector<int>> &grid)
    {
        n = grid.size(), m = grid[0].size();
        int ans = 0;
        vector<vector<vector<vector<int>>>> dp(
            n, vector<vector<vector<int>>>(
                   m, vector<vector<int>>(4, vector<int>(2, -1))));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    for (int d = 0; d < 4; d++)
                    {
                        ans = max(ans, solve(grid, i, j, d, true, 2, dp) + 1);
                    }
                }
            }
        }
        return ans;
    }
};