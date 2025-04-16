class Solution
{
public:
    void floydWarshall(vector<vector<int>> &dist)
    {
        int n = dist.size();
        for (int u = 0; u < n; u++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (dist[i][u] != 1e8 && dist[u][j] != 1e8 && dist[i][j] > dist[i][u] + dist[u][j])
                    {
                        dist[i][j] = dist[i][u] + dist[u][j];
                    }
                }
            }
        }
    }
};