class Solution
{
public:
    long long maximumTripletValue(vector<int> &nums)
    {
        long long ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int j = i + 1;
            while (j < n)
            {
                int k = j + 1;
                while (k < n)
                {
                    ans = max(ans, (long long)(nums[i] - nums[j]) * nums[k]);
                    k++;
                }
                j++;
            }
        }
        return ans;
    }
};