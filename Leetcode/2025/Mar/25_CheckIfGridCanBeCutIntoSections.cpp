class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> vec)
    {
        sort(vec.begin(), vec.end());
        vector<vector<int>> ans;
        for (auto v : vec)
        {
            if (ans.empty() || ans.back()[1] <= v[0])
            {
                ans.push_back(v);
            }
            else
            {
                ans.back()[1] = max(ans.back()[1], v[1]);
            }
        }
        return ans;
    }
    bool checkValidCuts(int n, vector<vector<int>> &rectangles)
    {
        vector<vector<int>> x, y;
        for (auto vec : rectangles)
        {
            vector<int> tempX = {vec[0], vec[2]};
            x.push_back(tempX);
            vector<int> tempY = {vec[1], vec[3]};
            y.push_back(tempY);
        }
        vector<vector<int>> mergedX = merge(x);
        vector<vector<int>> mergedY = merge(y);
        if (mergedX.size() >= 3 || mergedY.size() >= 3)
        {
            return true;
        }
        return false;
    }
};