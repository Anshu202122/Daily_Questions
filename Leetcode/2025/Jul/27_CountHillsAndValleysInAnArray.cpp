class Solution
{
public:
    int countHillValley(vector<int> &nums)
    {
        int n = nums.size(), count = 0, i = 0, j = 1;
        while (j + 1 < n)
        {
            if (nums[j] > nums[i] && nums[j] > nums[j + 1])
            {
                count++;
                i = j;
            }
            else if (nums[j] < nums[i] && nums[j] < nums[j + 1])
            {
                count++;
                i = j;
            }
            j++;
        }
        return count;
    }
};