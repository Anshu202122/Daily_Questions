class Solution
{
public:
    void inorder(Node *root, vector<int> &arr)
    {
        if (!root)
        {
            return;
        }
        inorder(root->left, arr);
        arr.push_back(root->data);
        inorder(root->right, arr);
    }
    void solve(Node *root, vector<int> &arr, int &i)
    {
        if (!root)
        {
            return;
        }
        solve(root->left, arr, i);
        root->data = arr[i];
        i++;
        solve(root->right, arr, i);
    }
    void correctBST(Node *root)
    {
        vector<int> arr;
        inorder(root, arr);
        sort(arr.begin(), arr.end());
        int idx = 0;
        solve(root, arr, idx);
    }
};