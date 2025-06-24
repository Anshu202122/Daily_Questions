class Solution
{
public:
    vector<int> findKDistantIndices(vector<int> &nums, int key, int k)
    {
        int n = nums.size(), i = 0;
        set<int> st;
        vector<int> ans;
        while (i < n)
        {
            if (nums[i] == key)
            {
                int minIdx = i - k, maxIdx = i + k;
                int j = max(minIdx, 0);
                while (j <= min(maxIdx, n - 1))
                {
                    st.insert(j);
                    j++;
                }
            }
            i++;
        }
        for (auto it = st.begin(); it != st.end(); it++)
        {
            ans.push_back(*it);
        }
        return ans;
    }
};