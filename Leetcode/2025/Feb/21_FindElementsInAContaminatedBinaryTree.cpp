class FindElements
{
public:
    TreeNode *newTree;
    set<int> st;
    void dfs(TreeNode *root, int x)
    {
        if (!root)
        {
            return;
        }
        root->val = x;
        st.insert(x);
        if (root->left != NULL)
        {
            dfs(root->left, (2 * x) + 1);
        }
        if (root->right != NULL)
        {
            dfs(root->right, (2 * x) + 2);
        }
    }
    FindElements(TreeNode *root)
    {
        newTree = root;
        dfs(newTree, 0);
    }
    bool find(int target)
    {
        if (st.find(target) != st.end())
        {
            return true;
        }
        return false;
    }
};