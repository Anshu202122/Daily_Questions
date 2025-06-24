class Solution
{
public:
    string maxSubseq(string &s, int k)
    {
        int n = s.length(), i = 0;
        string ans = "";
        stack<int> st;
        while (i < n)
        {
            while (!st.empty() && st.top() < s[i] && k > 0)
            {
                st.pop();
                k--;
            }
            st.push(s[i]);
            i++;
        }
        while (!st.empty() && k > 0)
        {
            st.pop();
            k--;
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