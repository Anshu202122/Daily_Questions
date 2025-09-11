class Solution
{
public:
    string sortVowels(string s)
    {
        int n = s.length(), j = 0;
        string vowel = "";
        for (int i = 0; i < n; i++)
        {
            char ch = tolower(s[i]);
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            {
                vowel += s[i];
            }
        }
        sort(vowel.begin(), vowel.end());
        for (int i = 0; i < n; i++)
        {
            char ch = tolower(s[i]);
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            {
                s[i] = vowel[j];
                j++;
            }
        }
        return s;
    }
};