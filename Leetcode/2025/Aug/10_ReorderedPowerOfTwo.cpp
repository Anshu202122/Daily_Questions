class Solution
{
public:
    string solve(int n)
    {
        string str = to_string(n);
        sort(str.begin(), str.end());
        return str;
    }
    bool reorderedPowerOf2(int n)
    {
        string s = solve(n);
        for (int i = 0; i < 30; i++)
        {
            int p = pow(2, i);
            if (solve(p) == s)
            {
                return true;
            }
        }
        return false;
    }
};