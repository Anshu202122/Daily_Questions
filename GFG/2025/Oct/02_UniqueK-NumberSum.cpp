class Solution {
public:
    void solve(int n, int k, int i, vector<int>& curr,
               vector<vector<int>>& ans) {
        if (n == 0 && curr.size() == k) {
            ans.push_back(curr);
            return;
        }
        if (n < 0 || curr.size() > k) {
            return;
        }
        for (int j = i; j <= 9; j++) {
            curr.push_back(j);
            solve(n - j, k, j + 1, curr, ans);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum(int n, int k) {
        vector<vector<int>> ans;
        vector<int> curr;
        solve(n, k, 1, curr, ans);
        return ans;
    }
};
