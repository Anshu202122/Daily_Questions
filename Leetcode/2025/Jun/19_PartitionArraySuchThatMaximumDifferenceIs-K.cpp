class Solution
{
public:
    int partitionArray(vector<int> &nums, int k)
    {
        int n = nums.size(), ans = 0;
        sort(nums.begin(), nums.end());
        int i = 0, j = 0;
        while (j < n)
        {
            int num = nums[i] + k;
            while (j < n && nums[j] <= num)
            {
                j++;
            }
            ans++;
            i = j;
        }
        return ans;
    }
};