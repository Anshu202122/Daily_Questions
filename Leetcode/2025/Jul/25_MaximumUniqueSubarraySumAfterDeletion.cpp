class Solution
{
public:
    int maxSum(vector<int> &nums)
    {
        int n = nums.size(), sum = 0, maxSum = nums[0];
        set<int> st;
        for (int i = 0; i < n; i++)
        {
            st.insert(nums[i]);
        }
        for (auto it = st.begin(); it != st.end(); it++)
        {
            sum = max(sum + *it, *it);
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};