class Solution
{
public:
    int maxLength(string &s)
    {
        stack<int> st;
        st.push(-1);
        int ans = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                st.push(i);
            }
            else
            {
                if (!st.empty())
                {
                    st.pop();
                }
                if (st.empty())
                {
                    st.push(i);
                }
                else
                {
                    ans = max(ans, i - st.top());
                }
            }
        }
        return ans;
    }
};