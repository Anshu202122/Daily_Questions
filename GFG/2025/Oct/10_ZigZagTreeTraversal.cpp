class Solution {
public:
    vector<int> zigZagTraversal(Node* root) {
        vector<vector<int>> ans;
        vector<int> result;
        queue<Node*> q;
        if (!root) {
            return result;
        }
        q.push(root);
        vector<int> temp;
        int curr = 1, next = 0;
        bool flag = true;
        while (!q.empty()) {
            Node* node = q.front();
            q.pop();
            temp.push_back(node->data);
            curr--;
            if (node->left) {
                q.push(node->left);
                next++;
            }
            if (node->right) {
                q.push(node->right);
                next++;
            }
            if (curr == 0) {
                if (flag) {
                    ans.push_back(temp);
                } else {
                    reverse(temp.begin(), temp.end());
                    ans.push_back(temp);
                }
                curr = next;
                next = 0;
                temp.clear();
                flag = !flag;
            }
        }
        for (int i = 0; i < ans.size(); i++) {
            for (int j = 0; j < ans[i].size(); j++) {
                result.push_back(ans[i][j]);
            }
        }
        return result;
    }
};
