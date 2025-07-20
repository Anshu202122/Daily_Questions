class Solution {
public:
    struct Node {
        string val;
        string sub;
        unordered_map<string, Node*> mp;
    };
    Node* get(string val) {
        Node* temp = new Node();
        temp->val = val;
        temp->sub = "";
        return temp;
    }
    void insert(Node* root, vector<string>& path) {
        for (auto& f : path) {
            if (!root->mp.count(f)) {
                root->mp[f] = get(f);
            }
            root = root->mp[f];
        }
    }
    string populate(Node* root, unordered_map<string, int>& subMp) {
        vector<pair<string, string>> subPaths;
        for (auto& [name, node] : root->mp) {
            string res = populate(node, subMp);
            subPaths.push_back({name, res});
        }
        sort(subPaths.begin(), subPaths.end());
        string p = "";
        for (auto& [name, path] : subPaths) {
            p += "(" + name + path + ")";
        }
        root->sub = p;
        if (!p.empty()) {
            subMp[p]++;
        }
        return p;
    }
    void removeDup(Node* root, unordered_map<string, int>& subMp) {
        for (auto it = root->mp.begin(); it != root->mp.end();) {
            string name = it->first;
            Node* c = it->second;
            if (!c->sub.empty() && subMp[c->sub] > 1) {
                it = root->mp.erase(it);
            } else {
                removeDup(c, subMp);
                it++;
            }
        }
    }
    void solve(Node* root, vector<string>& path, vector<vector<string>>& ans) {
        for (auto& [name, node] : root->mp) {
            path.push_back(name);
            ans.push_back(path);
            solve(node, path, ans);
            path.pop_back();
        }
    }
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        vector<vector<string>> ans;
        vector<string> path;
        unordered_map<string, int> subMp;
        Node* root = get("/");
        for (auto& p : paths) {
            insert(root, p);
        }
        populate(root, subMp);
        removeDup(root, subMp);
        solve(root, path, ans);
        return ans;
    }
};