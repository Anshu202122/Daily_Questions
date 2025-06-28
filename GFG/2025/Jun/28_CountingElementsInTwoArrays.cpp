class Solution
{
public:
    vector<int> countLessEq(vector<int> &a, vector<int> &b)
    {
        int n = a.size();
        sort(b.begin(), b.end());
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            int l = 0, r = b.size() - 1, count = 0;
            while (l <= r)
            {
                int mid = (l + r) / 2;
                if (b[mid] <= a[i])
                {
                    count = mid + 1;
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};