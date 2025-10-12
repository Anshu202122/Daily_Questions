class Solution {
  public:
    int distCandy(Node* root) {
        if (root == nullptr) return 0;
        int ans = 0;
        stack<pair<Node*, int>> stk;
        unordered_map<Node*, int> balance;
        stk.push({root, 0});
        while (!stk.empty()) {
            auto curr = stk.top();
            auto node = curr.first;
            auto state = curr.second;
            stk.pop();
            if (node == nullptr) continue;
            if (state == 0) {
                stk.push({node, 1});
                stk.push({node->left, 0});
                stk.push({node->right, 0});
            } 
            else {
                int leftBalance = balance[node->left];
                int rightBalance = balance[node->right];
                ans += abs(leftBalance) + abs(rightBalance);
                balance[node] = node->data + leftBalance + rightBalance - 1;
            }
        }
        return ans;   
    }
};
