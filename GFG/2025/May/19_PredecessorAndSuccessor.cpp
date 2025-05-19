class Solution
{
public:
    vector<Node *> findPreSuc(Node *root, int key)
    {
        vector<Node *> ans;
        Node *node = new Node(-1);
        Node* predecessor = NULL;
        Node* successor = NULL;
        Node *temp = root;
        while (temp)
        {
            if (key <= temp->data)
            {
                temp = temp->left;
            }
            else
            {
                predecessor = temp;
                temp = temp->right;
            }
        }
        if (predecessor == NULL)
        {
            ans.push_back(node);
        }
        else
        {
            ans.push_back(predecessor);
        }
        while (root)
        {
            if (key >= root->data)
            {
                root = root->right;
            }
            else
            {
                successor = root;
                root = root->left;
            }
        }
        if (successor == NULL)
        {
            ans.push_back(node);
        }
        else
        {
            ans.push_back(successor);
        }
        return ans;
    }
};