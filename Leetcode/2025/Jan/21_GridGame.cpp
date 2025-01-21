class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        long long firstSum = accumulate(begin(grid[0]), end(grid[0]), 0LL);
        long long secondSum = 0;
        long long ans = LONG_LONG_MAX;
        for (int i = 0; i < n; i++) {
            firstSum -= grid[0][i];
            long long maxVal = max(firstSum, secondSum);
            ans = min(ans, maxVal);
            secondSum += grid[1][i];
        }
        return ans;
    }
};