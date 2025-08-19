class Solution
{
public:
    vector<int> farMin(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> ans;
        vector<int> suf(n);
        suf[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            suf[i] = min(arr[i], suf[i + 1]);
        }
        for (int i = 0; i < n; i++)
        {
            int res = -1, low = i + 1, high = n - 1;
            while (low <= high)
            {
                int mid = (low + high) / 2;
                if (suf[mid] < arr[i])
                {
                    res = mid;
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
            ans.push_back(res);
        }
        return ans;
    }
};