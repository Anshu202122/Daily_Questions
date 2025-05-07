class Solution
{
public:
    void solve(Node *node, vector<int> &path, vector<vector<int>> &paths)
    {
        if (node == nullptr)
        {
            return;
        }
        path.push_back(node->data);
        if (node->left == nullptr && node->right == nullptr)
        {
            paths.push_back(path);
        }
        else
        {
            solve(node->left, path, paths);
            solve(node->right, path, paths);
        }
        path.pop_back();
    }
    vector<vector<int>> Paths(Node *root)
    {
        vector<vector<int>> paths;
        vector<int> path;
        solve(root, path, paths);
        return paths;
    }
};