class Solution
{
public:
    vector<int> solve(string &s)
    {
        int n = s.length();
        vector<int> arr(n);
        for (int i = 1, l = 0, r = 0; i < n; i++)
        {
            if (i <= r)
            {
                arr[i] = min(r - i + 1, arr[i - l]);
            }
            while (i + arr[i] < n && s[arr[i]] == s[i + arr[i]])
            {
                arr[i]++;
            }
            if (i + arr[i] - 1 > r)
            {
                l = i;
                r = i + arr[i] - 1;
            }
        }
        return arr;
    }
    int getLongestPrefix(string &s)
    {
        int n = s.length();
        vector<int> arr = solve(s);
        for (int i = n - 1; i >= 0; i--)
        {
            if (arr[i] == n - i)
            {
                return i;
            }
        }
        return -1;
    }
};