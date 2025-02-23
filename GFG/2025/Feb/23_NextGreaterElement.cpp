class Solution
{
public:
    vector<int> nextLargerElement(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--)
        {
            if (st.empty())
            {
                ans[i] = -1;
                st.push(arr[i]);
            }
            else
            {
                if (arr[i] < st.top())
                {
                    ans[i] = st.top();
                    st.push(arr[i]);
                }
                else
                {
                    while (!st.empty() && arr[i] >= st.top())
                    {
                        st.pop();
                    }
                    if (st.empty())
                    {
                        ans[i] = -1;
                        st.push(arr[i]);
                    }
                    else
                    {
                        ans[i] = st.top();
                        st.push(arr[i]);
                    }
                }
            }
        }
        return ans;
    }
};