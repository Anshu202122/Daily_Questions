class Solution {
public:
    Node* removekeys(Node* root, int l, int r) {
        if (root == NULL) {
            return NULL;
        }
        root->left = removekeys(root->left, l, r);
        root->right = removekeys(root->right, l, r);
        if (root->data < l) {
            return root->right;
        }
        if (root->data > r) {
            return root->left;
        }
        return root;
    }
};
