class Solution {
public:
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int dfs(vector<vector<int>>& grid, int i, int j, int m, int n) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) {
            return 0;
        }
        int count = grid[i][j];
        grid[i][j] = 0;
        for (vector<int>& d : dir) {
            int i_ = i + d[0];
            int j_ = j + d[1];
            count += dfs(grid, i_, j_, m, n);
        }
        return count;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] >= 0) {
                    ans = max(ans, dfs(grid, i, j, m, n));
                }
            }
        }
        return ans;
    }
};