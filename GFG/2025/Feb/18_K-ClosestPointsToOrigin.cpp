class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        priority_queue<pair<int, vector<int>>> pq;
        vector<vector<int>> ans;
        for (auto &i : points)
        {
            int x = i[0];
            int y = i[1];
            int dist = (x * x) + (y * y);
            pq.push({dist, i});
            if (pq.size() > k)
            {
                pq.pop();
            }
        }
        while (!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};