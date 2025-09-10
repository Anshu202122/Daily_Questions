class Solution
{
public:
    string largestSwap(string &s)
    {
        int n = s.length(), idx = -1, l = -1, r = -1;
        char ch = '0';
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] > ch)
            {
                ch = s[i];
                idx = i;
            }
            else if (s[i] < ch)
            {
                l = i;
                r = idx;
            }
        }
        if (l == -1)
        {
            return s;
        }
        swap(s[l], s[r]);
        return s;
    }
};