class Solution
{
public:
    double power(double b, int e)
    {
        if (e == 0)
        {
            return 1;
        }
        if (e < 0)
        {
            return 1 / power(b, -e);
        }
        double num = power(b, e / 2);
        if (e % 2 == 0)
        {
            return num * num;
        }
        else
        {
            return b * num * num;
        }
    }
};