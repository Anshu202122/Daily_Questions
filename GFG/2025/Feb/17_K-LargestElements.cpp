class Solution
{
public:
    vector<int> kLargest(vector<int> &arr, int k)
    {
        vector<int> ans;
        sort(arr.begin(), arr.end());
        int i = arr.size() - 1;
        while (k--)
        {
            ans.push_back(arr[i]);
            i--;
        }
        return ans;
    }
};