class Solution
{
public:
    bool check(vector<int> &nums, int i)
    {
        unordered_set<int> st;
        for (int j = i; j < nums.size(); j++)
        {
            if (st.count(nums[j]))
            {
                return false;
            }
            st.insert(nums[j]);
        }
        return true;
    }
    int minimumOperations(vector<int> &nums)
    {
        int n = nums.size(), ans = 0;
        for (int i = 0; i < n; i += 3)
        {
            if (check(nums, i))
            {
                return ans;
            }
            ans++;
        }
        return ans;
    }
};