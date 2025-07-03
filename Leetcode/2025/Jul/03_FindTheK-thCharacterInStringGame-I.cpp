class Solution
{
public:
    char kthCharacter(int k)
    {
        string s = "a";
        while (s.length() < k)
        {
            string str = "";
            int i = 0;
            while (i < s.length())
            {
                char ch = s[i];
                if (ch == 'z')
                {
                    str += 'a';
                }
                else
                {
                    str += ++ch;
                }
                i++;
            }
            s += str;
        }
        return s[k - 1];
    }
};