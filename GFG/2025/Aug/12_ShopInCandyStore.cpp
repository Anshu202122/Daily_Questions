class Solution
{
public:
    vector<int> minMaxCandy(vector<int> &prices, int k)
    {
        int n = prices.size(), minCost = 0, maxCost = 0;
        sort(prices.begin(), prices.end());
        vector<int> ans;
        int i = 0, j = n - 1;
        while (i <= j)
        {
            minCost += prices[i];
            int cnt = 0;
            while (cnt < k)
            {
                j--;
                cnt++;
            }
            i++;
        }
        ans.push_back(minCost);
        i = 0, j = n - 1;
        while (i <= j)
        {
            maxCost += prices[j];
            int cnt = 0;
            while (cnt < k)
            {
                i++;
                cnt++;
            }
            j--;
        }
        ans.push_back(maxCost);
        return ans;
    }
};