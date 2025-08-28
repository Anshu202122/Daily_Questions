class Solution
{
public:
    int maxOnes(vector<int> &arr, int k)
    {
        int n = arr.size(), cnt = 0, i = 0, j = 0, ans = 0;
        while (j < n)
        {
            while (j < n && cnt <= k)
            {
                if (arr[j] == 0)
                {
                    cnt++;
                }
                while (i < n && cnt > k)
                {
                    if (arr[i] == 0)
                    {
                        cnt--;
                    }
                    i++;
                }
                ans = max(ans, j - i + 1);
                j++;
            }
        }
        return ans;
    }
};