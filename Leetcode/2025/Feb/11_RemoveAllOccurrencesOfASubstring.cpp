class Solution
{
public:
    string removeOccurrences(string s, string part)
    {
        stack<char> st;
        string ans = "";
        int n = part.length();
        for (char &ch : s)
        {
            st.push(ch);
            if (st.size() >= n && part[n - 1] == st.top())
            {
                int i = n - 1;
                stack<char> temp;
                bool isMatch = true;
                while (i >= 0)
                {
                    if (st.top() == part[i])
                    {
                        temp.push(st.top());
                        st.pop();
                    }
                    else
                    {
                        isMatch = false;
                    }
                    i--;
                }
                if (!isMatch)
                {
                    while (!temp.empty())
                    {
                        st.push(temp.top());
                        temp.pop();
                    }
                }
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