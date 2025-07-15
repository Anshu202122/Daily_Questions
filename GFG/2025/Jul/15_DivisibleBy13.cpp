class Solution
{
public:
    bool divby13(string &s)
    {
        int ans = 0;
        for (char ch : s)
        {
            ans = (ans * 10 + (ch - '0')) % 13;
        }
        return ans == 0;
    }
};