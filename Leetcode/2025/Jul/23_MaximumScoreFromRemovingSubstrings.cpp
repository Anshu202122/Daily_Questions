class Solution
{
public:
    int maximumGain(string s, int x, int y)
    {
        int n = s.length(), ans = 0;
        stack<char> st;
        if (x > y)
        {
            for (char c : s)
            {
                if (c == 'b')
                {
                    if (!st.empty() && st.top() == 'a')
                    {
                        st.pop();
                        ans += x;
                        continue;
                    }
                }
                st.push(c);
            }
            string str = "";
            while (!st.empty())
            {
                str += st.top();
                st.pop();
            }
            reverse(str.begin(), str.end());
            for (char c : str)
            {
                if (c == 'a')
                {
                    if (!st.empty() && st.top() == 'b')
                    {
                        st.pop();
                        ans += y;
                        continue;
                    }
                }
                st.push(c);
            }
        }
        else
        {
            for (char c : s)
            {
                if (c == 'a')
                {
                    if (!st.empty() && st.top() == 'b')
                    {
                        st.pop();
                        ans += y;
                        continue;
                    }
                }
                st.push(c);
            }
            string str = "";
            while (!st.empty())
            {
                str += st.top();
                st.pop();
            }
            reverse(str.begin(), str.end());
            for (char c : str)
            {
                if (c == 'b')
                {
                    if (!st.empty() && st.top() == 'a')
                    {
                        st.pop();
                        ans += x;
                        continue;
                    }
                }
                st.push(c);
            }
        }
        return ans;
    }
};