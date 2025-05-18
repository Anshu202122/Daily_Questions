class Solution
{
public:
    vector<int> findSpiral(Node *root)
    {
        vector<vector<int>> arr;
        if (!root)
        {
            return {};
        }
        vector<int> temp;
        vector<int> ans;
        queue<Node *> q;
        q.push(root);
        int curr = 1, next = 0, level = 0;
        while (!q.empty())
        {
            Node *node = q.front();
            q.pop();
            temp.push_back(node->data);
            curr--;
            if (node->left)
            {
                q.push(node->left);
                next++;
            }
            if (node->right)
            {
                q.push(node->right);
                next++;
            }
            if (curr == 0)
            {
                if (level % 2 == 0)
                {
                    reverse(temp.begin(), temp.end());
                    arr.push_back(temp);
                }
                else
                {
                    arr.push_back(temp);
                }
                curr = next;
                next = 0;
                level++;
                temp.clear();
            }
        }
        for (int i = 0; i < arr.size(); i++)
        {
            for (int j = 0; j < arr[i].size(); j++)
            {
                ans.push_back(arr[i][j]);
            }
        }
        return ans;
    }
};