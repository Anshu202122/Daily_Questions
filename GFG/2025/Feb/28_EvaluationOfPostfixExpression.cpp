class Solution
{
public:
    int evaluate(vector<string> &arr)
    {
        stack<int> st;
        for (string str : arr)
        {
            if (isdigit(str[0]) || (str.size() > 1 && str[0] == '-'))
            {
                st.push(stoi(str));
            }
            else
            {
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                if (str == "+")
                {
                    st.push(num2 + num1);
                }
                else if (str == "-")
                {
                    st.push(num2 - num1);
                }
                else if (str == "*")
                {
                    st.push(num2 * num1);
                }
                else if (str == "/")
                {
                    st.push(num2 / num1);
                }
            }
        }
        return st.top();
    }
};