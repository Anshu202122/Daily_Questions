class Solution
{
public:
    int tupleSameProduct(vector<int> &nums)
    {
        int count = 0, n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++)
        {
            for (int j = n - 1; j > i; j--)
            {
                set<int> arr;
                for (int k = i + 1; k < j; k++)
                {
                    int pdt = nums[i] * nums[j];
                    if (pdt % nums[k] == 0)
                    {
                        int d = pdt / nums[k];
                        if (arr.find(d) != arr.end())
                        {
                            count++;
                        }
                        arr.insert(nums[k]);
                    }
                }
            }
        }
        return count * 8;
    }
};