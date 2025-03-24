class Solution
{
public:
    int countDays(int days, vector<vector<int>> &meetings)
    {
        int n = meetings.size(), ans = 0, end = 0;
        sort(meetings.begin(), meetings.end());
        for (auto &meet : meetings)
        {
            if (meet[0] > end)
            {
                ans += (meet[0] - end) - 1;
            }
            end = max(end, meet[1]);
        }
        if (days > end)
        {
            ans += (days - end);
        }
        return ans;
    }
};