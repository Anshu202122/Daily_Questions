class Solution
{
public:
    string answerString(string word, int numFriends)
    {
        if (numFriends == 1)
        {
            return word;
        }
        int n = word.length();
        int len = n - (numFriends - 1);
        string ans = "";
        for (int i = 0; i < n; i++)
        {
            int newLen = min(len, n - i);
            string str = word.substr(i, newLen);
            ans = max(ans, str);
        }
        return ans;
    }
};