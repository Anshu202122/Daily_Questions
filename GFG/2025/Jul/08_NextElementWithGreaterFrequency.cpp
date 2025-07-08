class Solution
{
public:
    vector<int> findGreater(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> ans(n);
        unordered_map<int, int> mp;
        stack<pair<int, int>> st;
        for (int a : arr)
        {
            mp[a]++;
        }
        ans[n - 1] = -1;
        st.push({arr[n - 1], mp[arr[n - 1]]});
        for (int i = n - 2; i >= 0; i--)
        {
            while (!st.empty() && mp[arr[i]] >= st.top().second)
            {
                st.pop();
            }
            if (st.empty())
            {
                ans[i] = -1;
            }
            else
            {
                ans[i] = st.top().first;
            }
            st.push({arr[i], mp[arr[i]]});
        }
        return ans;
    }
};