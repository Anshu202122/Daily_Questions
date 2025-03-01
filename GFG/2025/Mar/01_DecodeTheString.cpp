class Solution
{
public:
    string decodedString(string &s)
    {
        stack<char> st;
        int n = s.length();
        string ans;
        for (int i = 0; i < n; i++)
        {
            if (s[i] != ']')
            {
                st.push(s[i]);
            }
            else
            {
                string str, num;
                while (!st.empty() && st.top() != '[')
                {
                    str.push_back(st.top());
                    st.pop();
                }
                reverse(str.begin(), str.end());
                st.pop();
                while (!st.empty() && isdigit(st.top()))
                {
                    num = st.top() + num;
                    st.pop();
                }
                int number = stoi(num);
                string res;
                for (int j = 0; j < number; j++)
                {
                    res.append(str);
                }
                for (char c : res)
                {
                    st.push(c);
                }
            }
        }
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};