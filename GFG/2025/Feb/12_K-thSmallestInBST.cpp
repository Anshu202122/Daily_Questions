class Solution
{
public:
    int inorder(Node *root, int k, int &count)
    {
        if (!root)
        {
            return -1;
        }
        int left = inorder(root->left, k, count);
        if (left != -1)
        {
            return left;
        }
        count++;
        if (count == k)
        {
            return root->data;
        }
        int right = inorder(root->right, k, count);
        return right;
    }
    int kthSmallest(Node *root, int k)
    {
        int count = 0;
        return inorder(root, k, count);
    }
};