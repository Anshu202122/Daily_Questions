class Solution
{
public:
    vector<vector<int>> primeFactors(int num)
    {
        vector<vector<int>> factors;
        int count = 0;
        while (num % 2 == 0)
        {
            num /= 2;
            count++;
        }
        if (count > 0)
            factors.push_back({2, count});
        for (int i = 3; i * i <= num; i += 2)
        {
            count = 0;
            while (num % i == 0)
            {
                num /= i;
                count++;
            }
            if (count > 0)
                factors.push_back({i, count});
        }
        if (num > 1)
            factors.push_back({num, 1});

        return factors;
    }
    int legendre(int n, int p)
    {
        int count = 0;
        for (int power = p; power <= n; power *= p)
        {
            count += n / power;
        }
        return count;
    }
    int maxKPower(int n, int k)
    {
        vector<vector<int>> factors = primeFactors(k);
        int result = INT_MAX;
        for (auto &factor : factors)
        {
            int prime = factor[0];
            int expInK = factor[1];
            int countInFact = legendre(n, prime);
            result = min(result, countInFact / expInK);
        }
        return result;
    }
};