class Solution
{
public:
    int find(map<Node *, Node *> &mp, Node *target)
    {
        queue<Node *> q;
        q.push(target);
        map<Node *, int> vis;
        vis[target] = 1;
        int ans = 0;
        while (!q.empty())
        {
            int size = q.size();
            int flag = 0;
            for (int i = 0; i < size; i++)
            {
                Node *node = q.front();
                q.pop();
                if (node->left && !vis[node->left])
                {
                    flag = 1;
                    vis[node->left] = 1;
                    q.push(node->left);
                }
                if (node->right && !vis[node->right])
                {
                    flag = 1;
                    vis[node->right] = 1;
                    q.push(node->right);
                }
                if (mp[node] && !vis[mp[node]])
                {
                    flag = 1;
                    vis[mp[node]] = 1;
                    q.push(mp[node]);
                }
            }
            if (flag)
            {
                ans++;
            }
        }
        return ans;
    }
    Node *bfs(Node *root, map<Node *, Node *> &mp, int start)
    {
        queue<Node *> q;
        q.push(root);
        Node *res;
        while (!q.empty())
        {
            Node *node = q.front();
            if (node->data == start)
            {
                res = node;
            }
            q.pop();
            if (node->left)
            {
                mp[node->left] = node;
                q.push(node->left);
            }
            if (node->right)
            {
                mp[node->right] = node;
                q.push(node->right);
            }
        }
        return res;
    }
    int minTime(Node *root, int target)
    {
        map<Node *, Node *> mp;
        Node *start = bfs(root, mp, target);
        int ans = find(mp, start);
        return ans;
    }
};