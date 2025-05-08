class Solution
{
public:
    int minTimeToReach(vector<vector<int>> &moveTime)
    {
        priority_queue<pair<int, pair<int, pair<int, int>>>, vector<pair<int, pair<int, pair<int, int>>>>, greater<pair<int, pair<int, pair<int, int>>>>> pq;
        pq.push(make_pair(0, make_pair(1, make_pair(0, 0))));
        int row[4] = {-1, 0, 1, 0};
        int col[4] = {0, -1, 0, 1};
        int n = moveTime.size();
        int m = moveTime[0].size();
        int ans = INT_MAX;
        vector<vector<int>> visi(n, vector<int>(m, 0));
        while (pq.size() > 0)
        {
            int size = pq.size();
            for (int i = 0; i < size; i++)
            {
                auto frnt = pq.top();
                pq.pop();
                int time = frnt.first;
                int add = frnt.second.first;
                int x = frnt.second.second.first;
                int y = frnt.second.second.second;

                if (x == n - 1 && y == m - 1)
                {
                    ans = min(ans, time);
                }
                for (int i = 0; i < 4; i++)
                {
                    int p1 = x + row[i];
                    int p2 = y + col[i];
                    if (p1 >= 0 && p2 >= 0 && p1 < n && p2 < m &&
                        moveTime[p1][p2] <= time && visi[p1][p2] == 0)
                    {
                        int t = 0;
                        if (add == 1)
                        {
                            t = 2;
                        }
                        else
                        {
                            t = 1;
                        }
                        visi[p1][p2] = 1;
                        pq.push(make_pair(time + add, make_pair(t, make_pair(p1, p2))));
                    }
                    else if (p1 >= 0 && p2 >= 0 && p1 < n && p2 < m &&
                             moveTime[p1][p2] > time && visi[p1][p2] == 0)
                    {
                        int t = 0;
                        if (add == 1)
                        {
                            t = 2;
                        }
                        else
                        {
                            t = 1;
                        }
                        visi[p1][p2] = 1;
                        pq.push(make_pair(moveTime[p1][p2] + add, make_pair(t, make_pair(p1, p2))));
                    }
                }
            }
        }
        if (ans >= INT_MAX)
        {
            return -1;
        }
        return ans;
    }
};