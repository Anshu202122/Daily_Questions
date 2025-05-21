class Solution
{
public:
    int solve(int num, int m, int n)
    {
        int ans = 0;
        for (int i = 1; i <= m; i++)
        {
            ans += min(num / i, n);
        }
        return ans;
    }
    int kthSmallest(int m, int n, int k)
    {
        int l = 1, h = m * n;
        while (l < h)
        {
            int mid = (l + h) / 2;
            if (solve(mid, m, n) < k)
            {
                l = mid + 1;
            }
            else
            {
                h = mid;
            }
        }
        return l;
    }
};