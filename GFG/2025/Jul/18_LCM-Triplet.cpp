class Solution
{
public:
    int lcmTriplets(int n)
    {
        if (n < 3)
        {
            return n;
        }
        if (n % 2 == 1)
        {
            return n * (n - 1) * (n - 2);
        }
        else
        {
            if (n % 6 == 0)
            {
                return (n - 1) * (n - 2) * (n - 3);
            }
            else
            {
                return n * (n - 1) * (n - 3);
            }
        }
        return -1;
    }
};