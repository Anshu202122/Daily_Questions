class Solution
{
public:
    // Function to find the height of a binary tree.
    int height(Node *node)
    {
        if (!node)
        {
            return -1;
        }
        int left = height(node->left);
        int right = height(node->right);
        return max(left, right) + 1;
    }
};