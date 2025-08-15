class Solution
{
public:
    vector<vector<int>> insertInterval(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> ans;
        intervals.push_back(newInterval);
        int n = intervals.size(), i = 0;
        sort(intervals.begin(), intervals.end());
        while (i < n)
        {
            int s = intervals[i][0];
            int e = intervals[i][1];
            int j = i + 1;
            while (j < n && intervals[j][0] <= e)
            {
                e = max(e, intervals[j][1]);
                j++;
            }
            ans.push_back({s, e});
            i = j;
        }
        return ans;
    }
};