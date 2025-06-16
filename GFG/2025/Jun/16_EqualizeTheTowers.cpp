class Solution
{
public:
    int solve(vector<int> &heights, vector<int> &cost, int h)
    {
        int res = 0;
        int n = heights.size();
        for (int i = 0; i < n; i++)
        {
            res += cost[i] * abs(heights[i] - h);
        }
        return res;
    }
    int minCost(vector<int> &heights, vector<int> &cost)
    {
        int n = heights.size();
        int mini = INT_MAX, maxi = INT_MIN;
        for (auto val : heights)
        {
            mini = min(mini, val);
            maxi = max(maxi, val);
        }
        int low = mini, high = maxi, ans;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int val1 = solve(heights, cost, mid - 1);
            int val2 = solve(heights, cost, mid);
            int val3 = solve(heights, cost, mid + 1);
            if (val2 <= val1 && val2 <= val3)
            {
                ans = val2;
                break;
            }
            else if (val1 >= val2 && val2 >= val3)
            {
                low = mid + 1;
            }
            else if (val2 >= val1 && val3 >= val2)
            {
                high = mid - 1;
            }
        }
        return ans;
    }
};