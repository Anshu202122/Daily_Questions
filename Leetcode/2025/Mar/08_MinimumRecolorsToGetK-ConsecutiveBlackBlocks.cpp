class Solution
{
public:
    int minimumRecolors(string blocks, int k)
    {
        int n = blocks.length(), ans = n;
        for (int i = 0; i <= n - k; i++)
        {
            int cnt = 0;
            for (int j = i; j - i + 1 <= k; j++)
            {
                if (blocks[j] == 'W')
                {
                    cnt++;
                }
            }
            ans = min(ans, cnt);
        }
        return ans;
    }
};