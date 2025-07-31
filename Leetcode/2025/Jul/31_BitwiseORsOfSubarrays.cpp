class Solution
{
public:
    int subarrayBitwiseORs(vector<int> &arr)
    {
        int n = arr.size();
        set<int> prev;
        set<int> curr;
        set<int> ans;
        for (int i = 0; i < n; i++)
        {
            for (int num : prev)
            {
                curr.insert(arr[i] | num);
                ans.insert(arr[i] | num);
            }
            curr.insert(arr[i]);
            ans.insert(arr[i]);
            prev = curr;
            curr.clear();
        }
        return ans.size();
    }
};