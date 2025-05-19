class Solution
{
public:
    vector<Node *> findPreSuc(Node *root, int key)
    {
        vector<Node *> ans;
        Node *node = new Node(-1);
        Node *pre = NULL;
        Node *suc = NULL;
        Node *temp = root;
        while (temp)
        {
            if (key <= temp->data)
            {
                temp = temp->left;
            }
            else
            {
                pre = temp;
                temp = temp->right;
            }
        }
        if (pre == NULL)
        {
            ans.push_back(node);
        }
        else
        {
            ans.push_back(pre);
        }
        while (root)
        {
            if (key >= root->data)
            {
                root = root->right;
            }
            else
            {
                suc = root;
                root = root->left;
            }
        }
        if (suc == NULL)
        {
            ans.push_back(node);
        }
        else
        {
            ans.push_back(suc);
        }
        return ans;
    }
};