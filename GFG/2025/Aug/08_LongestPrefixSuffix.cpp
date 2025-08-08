class Solution
{
public:
    int getLPSLength(string &str)
    {
        int n = str.length(), p = 0, s = 1, ans = 0, pos = 1;
        while (p < n - 1 && s < n)
        {
            if (str[p] == str[s])
            {
                p++;
                s++;
                ans++;
            }
            else
            {
                p = 0;
                ans = 0;
                pos++;
                s = pos;
            }
        }
        return ans;
    }
};