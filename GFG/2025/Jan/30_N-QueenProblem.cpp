class Solution
{
public:
    void solve(int n, int c, vector<vector<int>> &ans, vector<int> &arr, vector<bool> &col, vector<bool> &leftDiag, vector<bool> &rightDiag)
    {
        for (int i = 0; i < n; i++)
        {
            if (c == n)
            {
                ans.push_back(arr);
                return;
            }
            if (!col[i] && !leftDiag[c - i + n - 1] && !rightDiag[i + c])
            {
                arr.push_back(i + 1);
                col[i] = true;
                leftDiag[c - i + n - 1] = true;
                rightDiag[i + c] = true;
                solve(n, c + 1, ans, arr, col, leftDiag, rightDiag);
                arr.pop_back();
                col[i] = false;
                leftDiag[c - i + n - 1] = false;
                rightDiag[i + c] = false;
            }
        }
    }
    vector<vector<int>> nQueen(int n)
    {
        vector<bool> col(n, false);
        vector<bool> leftDiag(2 * n - 1, false);
        vector<bool> rightDiag(2 * n - 1, false);
        vector<vector<int>> ans;
        vector<int> arr;
        solve(n, 0, ans, arr, col, leftDiag, rightDiag);
        return ans;
    }
};