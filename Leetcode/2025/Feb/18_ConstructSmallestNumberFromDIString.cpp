class Solution
{
public:
    bool solve(string &num, string &pattern)
    {
        int n = pattern.length();
        for (int i = 0; i < n; i++)
        {
            if ((pattern[i] == 'I' && num[i] > num[i + 1]) ||
                (pattern[i] == 'D' && num[i] < num[i + 1]))
            {
                return false;
            }
        }
        return true;
    }
    string smallestNumber(string pattern)
    {
        int n = pattern.length();
        string num = "";
        for (int i = 1; i <= n + 1; i++)
        {
            num += to_string(i);
        }
        while (!solve(num, pattern))
        {
            next_permutation(begin(num), end(num));
        }
        return num;
    }
};