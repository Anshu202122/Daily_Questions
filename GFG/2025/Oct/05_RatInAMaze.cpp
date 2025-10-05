class Solution {
public:
    int n;
    vector<string> ans;
    string s = "DLRU";
    vector<int> dr = {1, 0, 0, -1};
    vector<int> dc = {0, -1, 1, 0};
    void solve(vector<vector<int>>& maze, string curr, int i, int j) {
        if (i == n - 1 && j == n - 1) {
            ans.push_back(curr);
            return;
        }
        maze[i][j] = 0;
        for (int k = 0; k < 4; k++) {
            int i_ = i + dr[k];
            int j_ = j + dc[k];
            if (i_ >= 0 && j_ >= 0 && i_ < n && j_ < n && maze[i_][j_]) {
                curr.push_back(s[k]);
                solve(maze, curr, i_, j_);
                curr.pop_back();
            }
        }
        maze[i][j] = 1;
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        n = maze.size();
        if (maze[0][0] == 1 && maze[n - 1][n - 1] == 1) {
            solve(maze, "", 0, 0);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
