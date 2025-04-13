class Solution
{
public:
    unordered_map<Node *, Node *> mp;
    Node *cloneGraph(Node *node)
    {
        if (!node)
        {
            return NULL;
        }
        if (mp.find(node) != mp.end())
        {
            return mp[node];
        }
        Node *ans = new Node(node->val);
        mp[node] = ans;
        for (auto &it : node->neighbors)
        {
            ans->neighbors.push_back(cloneGraph(it));
        }
        return ans;
    }
};