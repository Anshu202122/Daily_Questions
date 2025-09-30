class Solution {
public:
    void solve(int n, vector<string>& ans, string s) {
        if (s.length() == n) {
            ans.push_back(s);
            return;
        }
        solve(n, ans, s + '0');
        solve(n, ans, s + '1');
    }
    vector<string> binstr(int n) {
        vector<string> ans;
        solve(n, ans, "");
        return ans;
    }
};
