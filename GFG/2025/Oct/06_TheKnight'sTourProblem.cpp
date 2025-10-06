class Solution {
public:
    int dx[8] = {-2,-1,1,2,2,1,-1,-2};
    int dy[8] = {1,2,2,1,-1,-2,-2,-1};
    vector<vector<int>> ans;
    bool solved = false;
    bool isValid(int x, int y, int n) {
        return (x >= 0 && y >= 0 && x < n && y < n && ans[x][y] == -1);
    }
    void backtrack(int x, int y, int step, int n) {
        if (solved) return;
        ans[x][y] = step;
        if (step == n * n - 1) {
            solved = true;
            return;
        }
        for (int i = 0; i < 8; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];
            if (isValid(newX, newY, n)) {
                backtrack(newX, newY, step + 1, n);
                if (solved) return;
            }
        }
        ans[x][y] = -1;
    }
    vector<vector<int>> knightTour(int n) {
        ans.assign(n, vector<int>(n, -1)); 
        backtrack(0, 0, 0, n);
        if (!solved) return {};
        return ans;
    }
};
