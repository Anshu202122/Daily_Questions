class Solution {
public:
    vector<vector<int>> dir{{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();
        vector<vector<int>> height(m, vector<int>(n, -1));
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isWater[i][j] == 1) {
                    height[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                pair<int, int> curr = q.front();
                q.pop();
                int i = curr.first;
                int j = curr.second;
                for (auto& d : dir) {
                    int i_ = i + d[0];
                    int j_ = j + d[1];
                    if (i_ >= 0 && i_ < m && j_ >= 0 && j_ < n &&
                        height[i_][j_] == -1) {
                        height[i_][j_] = height[i][j] + 1;
                        q.push({i_, j_});
                    }
                }
            }
        }
        return height;
    }
};