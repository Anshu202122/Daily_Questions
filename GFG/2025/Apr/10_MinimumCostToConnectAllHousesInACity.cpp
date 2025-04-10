class Solution
{
public:
    vector<int> parent, rank;
    int find(int x)
    {
        if (x == parent[x])
        {
            return x;
        }
        return parent[x] = find(parent[x]);
    }
    void uni(int x, int y)
    {
        int xp = find(x);
        int yp = find(y);
        if (xp == yp)
        {
            return;
        }
        if (rank[xp] > rank[yp])
        {
            parent[yp] = xp;
        }
        else if (rank[xp] < rank[yp])
        {
            parent[xp] = yp;
        }
        else
        {
            parent[xp] = yp;
            rank[yp]++;
        }
    }
    int solve(vector<vector<int>> &vec)
    {
        int sum = 0;
        for (auto &it : vec)
        {
            int u = it[0];
            int v = it[1];
            int d = it[2];
            int up = find(u);
            int vp = find(v);
            if (up != vp)
            {
                uni(u, v);
                sum += d;
            }
        }
        return sum;
    }
    int minCost(vector<vector<int>> &houses)
    {
        int n = houses.size();
        vector<vector<int>> vec;
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int x1 = houses[i][0];
                int y1 = houses[i][1];
                int x2 = houses[j][0];
                int y2 = houses[j][1];
                int d = abs(x1 - x2) + abs(y1 - y2);
                vec.push_back({i, j, d});
            }
        }
        auto comp = [&](auto &v1, auto &v2)
        {
            return v1[2] < v2[2];
        };
        sort(vec.begin(), vec.end(), comp);
        return solve(vec);
    }
};