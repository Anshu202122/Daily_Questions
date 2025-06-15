class Solution
{
public:
    int maxDiff(int num)
    {
        string str = to_string(num);
        int n = str.length();
        string a = "", b = "";
        char x1, x2;
        for (int i = 0; i < n; i++)
        {
            if (str[i] != '9')
            {
                x1 = str[i];
                break;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (str[i] > '1')
            {
                x2 = str[i];
                break;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (str[i] == x1)
            {
                a += '9';
            }
            else
            {
                a += str[i];
            }
        }
        if (str[0] == x2)
        {
            for (int i = 0; i < n; i++)
            {
                if (str[i] == x2)
                {
                    b += '1';
                }
                else
                {
                    b += str[i];
                }
            }
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                if (str[i] == x2)
                {
                    b += '0';
                }
                else
                {
                    b += str[i];
                }
            }
        }
        int newA = stoi(a), newB = stoi(b);
        return newA - newB;
    }
};