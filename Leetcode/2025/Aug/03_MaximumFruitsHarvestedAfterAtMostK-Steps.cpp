class Solution
{
public:
    int maxTotalFruits(vector<vector<int>> &fruits, int startPos, int k)
    {
        int n = fruits.size(), ans = 0;
        vector<int> pos(n);
        vector<int> fruitSum(n);
        pos[0] = fruits[0][0];
        fruitSum[0] = fruits[0][1];
        for (int i = 1; i < n; i++)
        {
            pos[i] = fruits[i][0];
            fruitSum[i] = fruitSum[i - 1] + fruits[i][1];
        }
        for (int d = 0; d <= k / 2; d++)
        {
            int i = startPos - d;
            int j = startPos + (k - (2 * d));
            int left = lower_bound(pos.begin(), pos.end(), i) - pos.begin();
            int right = upper_bound(pos.begin(), pos.end(), j) - pos.begin() - 1;
            if (left <= right)
            {
                int res = fruitSum[right] - (left > 0 ? fruitSum[left - 1] : 0);
                ans = max(ans, res);
            }
            i = startPos - (k - (2 * d));
            j = startPos + d;
            left = lower_bound(pos.begin(), pos.end(), i) - pos.begin();
            right = upper_bound(pos.begin(), pos.end(), j) - pos.begin() - 1;
            if (left <= right)
            {
                int res = fruitSum[right] - (left > 0 ? fruitSum[left - 1] : 0);
                ans = max(ans, res);
            }
        }
        return ans;
    }
};