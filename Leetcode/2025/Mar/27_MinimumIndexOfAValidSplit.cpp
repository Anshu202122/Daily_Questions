class Solution
{
public:
    int minimumIndex(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, int> mp1, mp2;
        for (int i = 0; i < n; i++)
        {
            mp2[nums[i]]++;
        }
        for (int i = 0; i < n; i++)
        {
            mp1[nums[i]]++;
            mp2[nums[i]]--;
            int n1 = i + 1, n2 = n - i - 1;
            if (mp1[nums[i]] > n1 / 2 && mp2[nums[i]] > n2 / 2)
            {
                return i;
            }
        }
        return -1;
    }
};