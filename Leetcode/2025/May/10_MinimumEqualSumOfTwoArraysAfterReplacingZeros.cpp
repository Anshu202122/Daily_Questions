class Solution
{
public:
    long long minSum(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size(), n2 = nums2.size();
        bool flag1 = false, flag2 = false;
        long long sum1 = 0, sum2 = 0;
        for (int i = 0; i < n1; i++)
        {
            sum1 += nums1[i];
            if (nums1[i] == 0)
            {
                flag1 = true;
                sum1++;
            }
        }
        for (int i = 0; i < n2; i++)
        {
            sum2 += nums2[i];
            if (nums2[i] == 0)
            {
                flag2 = true;
                sum2++;
            }
        }
        if ((sum1 < sum2 && !flag1) || (sum1 > sum2 && !flag2))
        {
            return -1;
        }
        return max(sum1, sum2);
    }
};