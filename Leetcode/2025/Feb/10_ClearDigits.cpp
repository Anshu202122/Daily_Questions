class Solution
{
public:
    string clearDigits(string s)
    {
        stack<char> st;
        string ans = "";
        for (int i = 0; i < s.length(); i++)
        {
            if (!st.empty() && isdigit(s[i]) == 1)
            {
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }
        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};