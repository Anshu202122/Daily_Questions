class Solution
{
public:
    int activitySelection(vector<int> &start, vector<int> &finish)
    {
        int n = start.size(), ans = 1;
        vector<pair<int, int>> arr;
        for (int i = 0; i < n; i++)
        {
            arr.push_back({start[i], finish[i]});
        }
        auto comp = [&](auto &a, auto &b)
        {
            return a.second < b.second;
        };
        sort(arr.begin(), arr.end(), comp);
        int curr = arr[0].second;
        for (int i = 0; i < n; i++)
        {
            if (arr[i].first > curr)
            {
                ans++;
                curr = arr[i].second;
            }
        }
        return ans;
    }
};