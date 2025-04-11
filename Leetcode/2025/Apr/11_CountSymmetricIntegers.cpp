class Solution
{
public:
    int countSymmetricIntegers(int low, int high)
    {
        int ans = 0;
        for (int i = low; i <= high; i++)
        {
            string str = to_string(i);
            int sum1 = 0, sum2 = 0, len = str.length();
            if (len % 2 != 0)
            {
                continue;
            }
            for (int j = 0; j < len / 2; j++)
            {
                sum1 += str[j] - '0';
            }
            for (int j = len / 2; j < len; j++)
            {
                sum2 += str[j] - '0';
            }
            if (sum1 == sum2)
            {
                ans++;
            }
        }
        return ans;
    }
};