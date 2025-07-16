class Solution
{
public:
    int countNumbers(int n)
    {
        int ans = 0, e = sqrt(n);
        vector<int> prime(e + 1);
        for (int i = 1; i <= e; i++)
        {
            prime[i] = i;
        }
        for (int i = 2; i <= e; i++)
        {
            if (prime[i] == i)
            {
                for (int j = i * i; j <= e; j += i)
                {
                    if (prime[j] == j)
                    {
                        prime[j] = i;
                    }
                }
            }
        }
        for (int i = 2; i <= e; i++)
        {
            int a = prime[i], b = prime[i / prime[i]];
            if (a * b == i && b != 1 && a != b)
            {
                ans++;
            }
            else if (prime[i] == i && pow(i, 8) <= n)
            {
                ans++;
            }
        }
        return ans;
    }
};