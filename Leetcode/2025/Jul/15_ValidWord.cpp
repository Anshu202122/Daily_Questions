class Solution
{
public:
    bool isValid(string word)
    {
        int n = word.length();
        bool vowel = false, consonant = false;
        ;
        if (n < 3)
        {
            return false;
        }
        for (int i = 0; i < n; i++)
        {
            char ch = tolower(word[i]);
            if (!isalnum(word[i]))
            {
                return false;
            }
            else if (!isdigit(word[i]) &&
                     (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' ||
                      ch == 'u'))
            {
                vowel = true;
            }
            else if (!isdigit(word[i]) &&
                     (ch != 'a' || ch != 'e' || ch != 'i' || ch != 'o' ||
                      ch != 'u'))
            {
                consonant = true;
            }
        }
        if (!vowel)
        {
            return false;
        }
        if (!consonant)
        {
            return false;
        }
        return true;
    }
};