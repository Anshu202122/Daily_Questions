class Solution
{
public:
    bool solve(Node *l, Node *r)
    {
        if (l == NULL && r == NULL)
        {
            return true;
        }
        if ((l == NULL && r != NULL) || (r == NULL && l != NULL))
        {
            return false;
        }
        if (l->data == r->data)
        {
            if (solve(l->left, r->right) && solve(l->right, r->left))
            {
                return true;
            }
        }
        return false;
    }
    bool isSymmetric(Node *root)
    {
        return solve(root->left, root->right);
    }
};