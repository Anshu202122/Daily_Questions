class Solution
{
public:
    int idx = 0;
    void preorder(Node *root, vector<int> &ans)
    {
        if (!root)
        {
            ans.push_back(-1);
            return;
        }
        ans.push_back(root->data);
        preorder(root->left, ans);
        preorder(root->right, ans);
    }
    vector<int> serialize(Node *root)
    {
        vector<int> ans;
        preorder(root, ans);
        return ans;
    }
    Node *deSerialize(vector<int> &arr)
    {
        int num = arr[idx];
        idx++;
        if (num == -1)
        {
            return NULL;
        }
        Node *root = new Node(num);
        root->left = deSerialize(arr);
        root->right = deSerialize(arr);
        return root;
    }
};