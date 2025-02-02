class Solution
{
public:
    void solve(Node *root, int i, vector<vector<int>> &ans)
    {
        if (!root)
        {
            return;
        }
        if (ans.size() <= i)
        {
            ans.push_back({});
        }
        ans[i].push_back(root->data);
        solve(root->left, i + 1, ans);
        solve(root->right, i + 1, ans);
    }
    vector<vector<int>> levelOrder(Node *root)
    {
        vector<vector<int>> ans;
        solve(root, 0, ans);
        return ans;
    }
};