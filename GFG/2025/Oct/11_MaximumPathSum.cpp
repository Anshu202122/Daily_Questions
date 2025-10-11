class Solution {
public:
    int ans;
    int solve(Node* root) {
        if (!root) {
            return 0;
        }
        int l = solve(root->left);
        int r = solve(root->right);
        int both = l + r + root->data;
        int one = max(l, r) + root->data;
        int onlyRoot = root->data;
        ans = max({ans, both, one, onlyRoot});
        return max(one, onlyRoot);
    }
    int findMaxSum(Node* root) {
        ans = INT_MIN;
        solve(root);
        return ans;
    }
};
