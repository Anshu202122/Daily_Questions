class Solution
{
public:
    vector<int> rightArr(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> right(n, n);
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && arr[i] < arr[st.top()])
            {
                right[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return right;
    }
    vector<int> leftArr(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> left(n, -1);
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && arr[i] < arr[st.top()])
            {
                st.pop();
            }
            if (!st.empty())
            {
                left[i] = st.top();
            }
            st.push(i);
        }
        return left;
    }
    int getMaxArea(vector<int> &arr)
    {
        vector<int> left = leftArr(arr);
        vector<int> right = rightArr(arr);
        int ans = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            int b = right[i] - left[i] - 1;
            int area = arr[i] * b;
            ans = max(ans, area);
        }
        return ans;
    }
};