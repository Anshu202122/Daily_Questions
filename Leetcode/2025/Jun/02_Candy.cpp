class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int n = ratings.size(), ans = 0;
        vector<int> lr(n, 1);
        vector<int> rl(n, 1);
        for (int i = 1; i < n; i++)
        {
            if (ratings[i] > ratings[i - 1])
            {
                lr[i] = max(lr[i], lr[i - 1] + 1);
            }
        }
        for (int i = n - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1])
            {
                rl[i] = max(rl[i], rl[i + 1] + 1);
            }
        }
        for (int i = 0; i < n; i++)
        {
            ans += max(lr[i], rl[i]);
        }
        return ans;
    }
};