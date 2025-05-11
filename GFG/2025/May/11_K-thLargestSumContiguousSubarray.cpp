class Solution
{
public:
    int kthLargest(vector<int> &arr, int k)
    {
        int n = arr.size();
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = i; j < n; j++)
            {
                sum += arr[j];
                ans.push_back(sum);
            }
        }
        sort(ans.begin(), ans.end());
        reverse(ans.begin(), ans.end());
        return ans[k - 1];
    }
};