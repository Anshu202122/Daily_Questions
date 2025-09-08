class Solution
{
public:
    vector<int> getNoZeroIntegers(int n)
    {
        int a = n, b = 0, p = 1;
        while (n > 1)
        {
            int take = 1;
            if (n % 10 == 1)
            {
                take = 2;
            }
            a = a - take * p;
            b = b + take * p;
            p *= 10;
            n = (n - take) / 10;
        }
        return {a, b};
    }
};