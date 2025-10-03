class Solution {
public:
    int n;
    vector<string> ans;
    vector<string> keys = {"",    "",    "abc",  "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void solve(vector<int>& arr, string temp, int i) {
        if (i == n) {
            ans.push_back(temp);
            return;
        }
        int idx = arr[i];
        if (idx < 2 || idx > 9) {
            solve(arr, temp, i + 1);
            return;
        }
        for (char ch : keys[idx]) {
            temp.push_back(ch);
            solve(arr, temp, i + 1);
            temp.pop_back();
        }
    }
    vector<string> possibleWords(vector<int>& arr) {
        n = arr.size();
        solve(arr, "", 0);
        return ans;
    }
};
