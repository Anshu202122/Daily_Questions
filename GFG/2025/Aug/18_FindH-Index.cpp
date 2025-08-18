class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        int n = citations.size(), i = 0;
        sort(citations.begin(), citations.end(), greater<int>());
        while (i < n && citations[i] > i)
        {
            i++;
        }
        return i;
    }
};