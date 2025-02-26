class Solution
{
public:
    vector<int> maxOfMins(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> ans(n, 0);
        vector<int> nums(n, 0);
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
            {
                int num = st.top();
                st.pop();
                int win = st.empty() ? i : i - st.top() - 1;
                nums[num] = win;
            }
            st.push(i);
        }
        while (!st.empty())
        {
            int num = st.top();
            st.pop();
            int win = st.empty() ? n : n - st.top() - 1;
            nums[num] = win;
        }
        for (int i = 0; i < n; i++)
        {
            int size = nums[i] - 1;
            ans[size] = max(ans[size], arr[i]);
        }
        for (int i = n - 2; i >= 0; i--)
        {
            ans[i] = max(ans[i], ans[i + 1]);
        }
        return ans;
    }
};