class Solution
{
public:
    int nCr(int n, int r)
    {
        double ans = 1;
        for (int i = 1; i <= r; i++)
        {
            ans = ans * (n - r + i) / i;
        }
        return (int)ans;
    }
};