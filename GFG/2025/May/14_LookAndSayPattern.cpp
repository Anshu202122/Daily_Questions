class Solution
{
public:
    string countAndSay(int n)
    {
        if (n == 1)
        {
            return "1";
        }
        string str = countAndSay(n - 1);
        string ans = "";
        for (int i = 0; i < str.length(); i++)
        {
            char ch = str[i];
            int count = 1;
            while (i < str.length() - 1 && str[i] == str[i + 1])
            {
                count++;
                i++;
            }
            ans += to_string(count) + string(1, ch);
        }
        return ans;
    }
};