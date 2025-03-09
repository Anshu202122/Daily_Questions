class Solution
{
public:
    int solve(int l, int r, string &s)
    {
        int count = 0;
        while (l >= 0 && r < s.length())
        {
            if (s[l] == s[r])
            {
                count++;
                l--;
                r++;
            }
            else
            {
                break;
            }
        }
        return count;
    }
    int countPS(string &s)
    {
        int n = s.length();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += solve(i - 1, i + 1, s);
        }
        for (int i = 1; i < n; i++)
        {
            ans += solve(i - 1, i, s);
        }
        return ans;
    }
};