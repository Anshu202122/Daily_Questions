class Solution
{
public:
    vector<int> nextLargerElement(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        for (int i = 2 * n - 1; i >= 0; i--)
        {
            while (!st.empty() && st.top() <= arr[i % n])
            {
                st.pop();
            }
            if (st.empty())
            {
                ans[i % n] = -1;
            }
            else
            {
                ans[i % n] = st.top();
            }
            st.push(arr[i % n]);
        }
        return ans;
    }
};