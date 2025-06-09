class Solution
{
public:
    bool solve(Node *root, int minEle, int maxEle)
    {
        if (!root)
        {
            return false;
        }
        if (!root->left && !root->right && minEle == maxEle)
        {
            return true;
        }
        return solve(root->left, minEle, root->data - 1) || solve(root->right, root->data + 1, maxEle);
    }
    bool isDeadEnd(Node *root)
    {
        return solve(root, 1, INT_MAX);
    }
};