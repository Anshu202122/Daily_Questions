class Solution
{
public:
    int sumSubstrings(string &s)
    {
        int n = s.length(), sum = 0;
        for (int i = 0; i < n; i++)
        {
            string str = "";
            for (int j = i; j < n; j++)
            {
                str += s[j];
                sum += stoi(str);
            }
        }
        return sum;
    }
};