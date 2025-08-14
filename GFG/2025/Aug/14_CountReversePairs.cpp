class Solution
{
public:
    int merge(vector<int> &arr, int low, int mid, int high)
    {
        int cnt = 0, j = mid + 1;
        for (int i = low; i <= mid; i++)
        {
            while (j <= high && arr[i] > 2LL * arr[j])
            {
                j++;
            }
            cnt += (j - (mid + 1));
        }
        vector<int> temp;
        int l = low, r = mid + 1;
        while (l <= mid && r <= high)
        {
            if (arr[l] <= arr[r])
            {
                temp.push_back(arr[l]);
                l++;
            }
            else
            {
                temp.push_back(arr[r]);
                r++;
            }
        }
        while (l <= mid)
        {
            temp.push_back(arr[l]);
            l++;
        }
        while (r <= high)
        {
            temp.push_back(arr[r]);
            r++;
        }
        for (int i = low; i <= high; i++)
        {
            arr[i] = temp[i - low];
        }
        return cnt;
    }
    int mergeSort(vector<int> &arr, int low, int high)
    {
        if (low >= high)
        {
            return 0;
        }
        int mid = low + (high - low) / 2;
        int cnt = mergeSort(arr, low, mid) + mergeSort(arr, mid + 1, high) + merge(arr, low, mid, high);
        return cnt;
    }
    int countRevPairs(vector<int> &arr)
    {
        int n = arr.size();
        return mergeSort(arr, 0, n - 1);
    }
};