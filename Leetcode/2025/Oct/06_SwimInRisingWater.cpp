class Solution {
public:
    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int n;
    bool isPossible(vector<vector<int>>& grid, int i, int j, int t,
                    vector<vector<bool>>& vis) {
        if (i < 0 || i >= n || j < 0 || j >= n || vis[i][j] == true ||
            grid[i][j] > t) {
            return false;
        }
        vis[i][j] = true;
        if (i == n - 1 && j == n - 1) {
            return true;
        }
        for (auto d : dir) {
            int i_ = i + d[0];
            int j_ = j + d[1];
            if (isPossible(grid, i_, j_, t, vis)) {
                return true;
            }
        }
        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();
        int l = 0, r = (n * n) - 1, ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            vector<vector<bool>> vis(n, vector<bool>(n, false));
            if (isPossible(grid, 0, 0, mid, vis)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
