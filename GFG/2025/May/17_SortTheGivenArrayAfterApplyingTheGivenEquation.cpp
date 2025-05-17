class Solution
{
public:
    vector<int> sortArray(vector<int> &arr, int A, int B, int C)
    {
        vector<int> ans;
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            long num = A * (arr[i] * arr[i]) + B * arr[i] + C;
            ans.push_back(num);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};