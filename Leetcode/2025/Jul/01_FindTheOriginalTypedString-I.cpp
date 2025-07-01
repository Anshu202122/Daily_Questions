class Solution
{
public:
    int possibleStringCount(string word)
    {
        int n = word.length(), ans = 0, i = 0, j = 0;
        while (j < n)
        {
            int count = 0;
            while (j < n && word[i] == word[j])
            {
                count++;
                j++;
            }
            if (count > 1)
            {
                ans += (count - 1);
            }
            i = j;
        }
        return ans + 1;
    }
};