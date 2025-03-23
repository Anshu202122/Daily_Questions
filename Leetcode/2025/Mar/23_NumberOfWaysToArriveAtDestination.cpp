class Solution
{
public:
    typedef pair<long long, int> p;
    int mod = 1e9 + 7;
    int countPaths(int n, vector<vector<int>> &roads)
    {
        unordered_map<int, vector<pair<int, int>>> mp;
        for (auto &road : roads)
        {
            int u = road[0];
            int v = road[1];
            int t = road[2];
            mp[u].push_back({v, t});
            mp[v].push_back({u, t});
        }
        priority_queue<p, vector<p>, greater<p>> pq;
        vector<long long> ans(n, LLONG_MAX);
        vector<int> count(n, 0);
        ans[0] = 0;
        count[0] = 1;
        pq.push({0, 0});
        while (!pq.empty())
        {
            long long time = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for (auto &vec : mp[node])
            {
                int ngbr = vec.first;
                int road = vec.second;
                if (time + road < ans[ngbr])
                {
                    ans[ngbr] = time + road;
                    pq.push({ans[ngbr], ngbr});
                    count[ngbr] = count[node];
                }
                else if (time + road == ans[ngbr])
                {
                    count[ngbr] = (count[ngbr] + count[node]) % mod;
                }
            }
        }
        return count[n - 1];
    }
};