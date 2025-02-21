class Solution
{
public:
    bool isBalanced(string &s)
    {
        stack<char> st;
        for (char &ch : s)
        {
            if (ch == '[' || ch == '(' || ch == '{')
            {
                st.push(ch);
            }
            else
            {
                if (!st.empty())
                {
                    if (ch == ')' && st.top() == '(')
                    {
                        st.pop();
                    }
                    else if (ch == ']' && st.top() == '[')
                    {
                        st.pop();
                    }
                    else if (ch == '}' && st.top() == '{')
                    {
                        st.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
        }
        if (st.empty())
        {
            return true;
        }
        return false;
    }
};