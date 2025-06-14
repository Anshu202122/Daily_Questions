class Solution
{
public:
    int minMaxDifference(int num)
    {
        string str = to_string(num);
        string minStr = "", maxStr = "";
        char firstNotNine, firstNotZero;
        int n = str.length();
        for (int i = 0; i < n; i++)
        {
            if (str[i] != '9')
            {
                firstNotNine = str[i];
                break;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (str[i] != '0')
            {
                firstNotZero = str[i];
                break;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (str[i] == firstNotNine)
            {
                maxStr += '9';
            }
            else
            {
                maxStr += str[i];
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (str[i] == firstNotZero)
            {
                minStr += '0';
            }
            else
            {
                minStr += str[i];
            }
        }
        int num1 = stoi(maxStr), num2 = stoi(minStr);
        return num1 - num2;
    }
};