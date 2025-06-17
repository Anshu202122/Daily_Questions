int mod = 1e9 + 7;
class Solution
{
public:
    int find(long long a, long long b)
    {
        if (b == 0)
        {
            return 1;
        }
        long long half = find(a, b / 2);
        long long ans = (half * half) % mod;
        if (b % 2 == 1)
        {
            ans = (ans * a) % mod;
        }
        return ans;
    }
    long long nCr(int n, int r, vector<long long> &fact, vector<long long> &fermatFact)
    {
        return fact[n] * fermatFact[n - r] % mod * fermatFact[r] % mod;
    }
    int countGoodArrays(int n, int m, int k)
    {
        vector<long long> fact(n + 1, 1);
        vector<long long> fermatFact(n + 1, 1);
        fact[0] = 1;
        fact[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            fact[i] = (fact[i - 1] * i) % mod;
        }
        for (int i = 0; i <= n; i++)
        {
            fermatFact[i] = find(fact[i], mod - 2);
        }
        long long ans = nCr(n - 1, k, fact, fermatFact);
        ans = (ans * m) % mod;
        ans = (ans * find(m - 1, n - k - 1)) % mod;
        return ans;
    }
};