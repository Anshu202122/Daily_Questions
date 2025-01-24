class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> newGraph(n);
        queue<int> q;
        vector<int> indegree(n, 0);
        vector<bool> isSafe(n, false);
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            for (int& v : graph[i]) {
                newGraph[v].push_back(i);
                indegree[i]++;
            }
        }
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            isSafe[u] = true;
            for (int& v : newGraph[u]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (isSafe[i]) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};