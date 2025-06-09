class Solution
{
public:
    string add(string &s1, string &s2)
    {
        if (s1.length() < s2.length())
        {
            swap(s1, s2);
        }
        int len1 = s1.length(), len2 = s2.length(), carry = 0;
        string sum = "";
        for (int i = 0; i < len2; i++)
        {
            int d1 = s1[len1 - 1 - i] - '0';
            int d2 = s2[len2 - 1 - i] - '0';
            int digit = (d1 + d2 + carry) % 10;
            carry = (d1 + d2 + carry) / 10;
            sum = char(digit + '0') + sum;
        }
        for (int i = len2; i < len1; i++)
        {
            int d = s1[len1 - 1 - i] - '0';
            int digit = (d + carry) % 10;
            carry = (d + carry) / 10;
            sum = char(digit + '0') + sum;
        }
        if (carry)
        {
            sum = char(carry + '0') + sum;
        }
        return sum;
    }
    bool solve(string &s, int start, int i, int j)
    {
        string p1 = s.substr(start, i);
        string p2 = s.substr(start + i, j);
        string p3 = add(p1, p2);
        int len = p3.length();
        if (start + i + j + len > s.length())
        {
            return false;
        }
        if (p3 == s.substr(start + i + j, len))
        {
            if (start + i + j + len == s.length())
            {
                return true;
            }
            return solve(s, start + i, j, len);
        }
        return false;
    }
    bool isSumString(string &s)
    {
        int n = s.length();
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; i + j < n; j++)
            {
                if (solve(s, 0, i, j))
                {
                    return true;
                }
            }
        }
        return false;
    }
};