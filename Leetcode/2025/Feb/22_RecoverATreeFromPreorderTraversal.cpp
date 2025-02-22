class Solution
{
public:
    TreeNode *solve(string s, int &i, int depth)
    {
        if (i >= s.length())
        {
            return NULL;
        }
        int j = i;
        while (j < s.length() && s[j] == '-')
        {
            j++;
        }
        int dash = j - i;
        if (dash != depth)
        {
            return NULL;
        }
        i += dash;
        int num = 0;
        while (i < s.length() && isdigit(s[i]))
        {
            num = (num * 10) + (s[i] - '0');
            i++;
        }
        TreeNode *root = new TreeNode(num);
        root->left = solve(s, i, depth + 1);
        root->right = solve(s, i, depth + 1);
        return root;
    }
    TreeNode *recoverFromPreorder(string traversal)
    {
        int n = traversal.length();
        int i = 0;
        int depth = 0;
        return solve(traversal, i, depth);
    }
};