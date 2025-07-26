class Solution
{
public:
    long long maxSubarrays(int n, vector<vector<int>> &conflictingPairs)
    {
        long long ans = 0;
        int maxConf = 0, secondMax = 0;
        vector<vector<int>> points(n + 1);
        vector<long long> extra(n + 1, 0);
        for (auto &p : conflictingPairs)
        {
            int a = min(p[0], p[1]);
            int b = max(p[0], p[1]);
            points[b].push_back(a);
        }
        for (int i = 1; i <= n; i++)
        {
            for (int &a : points[i])
            {
                if (a >= maxConf)
                {
                    secondMax = maxConf;
                    maxConf = a;
                }
                else if (a > secondMax)
                {
                    secondMax = a;
                }
            }
            ans += i - maxConf;
            extra[maxConf] += maxConf - secondMax;
        }
        return ans + *max_element(extra.begin(), extra.end());
    }
};