class Solution
{
public:
    vector<int> printKClosest(vector<int> arr, int k, int x)
    {
        vector<int> ans;
        int n = arr.size();
        int low = 0, high = n - 1, idx = -1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (arr[mid] < x)
            {
                idx = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        int l = idx, r = idx + 1;
        if (arr[r] == x)
        {
            r++;
        }
        while (l >= 0 && r < n && ans.size() < k)
        {
            int a = abs(arr[l] - x), b = abs(arr[r] - x);
            if (a < b)
            {
                ans.push_back(arr[l]);
                l--;
            }
            else
            {
                ans.push_back(arr[r]);
                r++;
            }
        }
        while (l >= 0 && ans.size() < k)
        {
            ans.push_back(arr[l]);
            l--;
        }
        while (r < n && ans.size() < k)
        {
            ans.push_back(arr[r]);
            r++;
        }
        return ans;
    }
};