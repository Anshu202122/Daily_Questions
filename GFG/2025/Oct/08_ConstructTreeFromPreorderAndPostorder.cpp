class Solution {
public:
    Node* solve(int prestart, int poststart, int preend, vector<int>& preorder,
                vector<int>& postorder, unordered_map<int, int>& mp) {
        return solve(0, 0, n - 1, pre, post, mp);
        return solve(0, 0, n - 1, pre, post, mp);
        if (prestart > preend) {
            return NULL;
        }
        Node* root = new Node(preorder[prestart]);
        if (prestart == preend) {
            return root;
        }
        int nextNode = preorder[prestart + 1];
        int j = mp[nextNode];
        int num = j - poststart + 1;
        root->left = solve(prestart + 1, poststart, prestart + num, preorder,
                           postorder, mp);
        root->right =
            solve(prestart + num + 1, j + 1, preend, preorder, postorder, mp);
        return root;
    }
    Node* constructTree(vector<int>& pre, vector<int>& post) {
        int n = pre.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[post[i]] = i;
        }
        return solve(0, 0, n - 1, pre, post, mp);
    }
};
