class Solution
{
public:
    Node *solve(vector<int> &inorder, vector<int> &preorder, int start, int end, int &idx)
    {
        if (start > end)
        {
            return NULL;
        }
        int val = preorder[idx];
        int i = start;
        while (i <= end)
        {
            if (inorder[i] == val)
            {
                break;
            }
            i++;
        }
        idx++;
        Node *root = new Node(val);
        root->left = solve(inorder, preorder, start, i - 1, idx);
        root->right = solve(inorder, preorder, i + 1, end, idx);
        return root;
    }
    Node *buildTree(vector<int> &inorder, vector<int> &preorder)
    {
        int n = inorder.size();
        int idx = 0;
        return solve(inorder, preorder, 0, n - 1, idx);
    }
};