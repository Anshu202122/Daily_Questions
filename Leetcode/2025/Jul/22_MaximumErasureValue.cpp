class Solution
{
public:
    int maximumUniqueSubarray(vector<int> &nums)
    {
        int n = nums.size(), sum = 0, maxSum = 0, i = 0, j = 0;
        set<int> st;
        while (j < n)
        {
            while (j < n && st.find(nums[j]) == st.end())
            {
                sum += nums[j];
                st.insert(nums[j]);
                maxSum = max(maxSum, sum);
                j++;
            }
            while (j < n && i < j && st.find(nums[j]) != st.end())
            {
                sum -= nums[i];
                st.erase(nums[i]);
                i++;
            }
        }
        return maxSum;
    }
};