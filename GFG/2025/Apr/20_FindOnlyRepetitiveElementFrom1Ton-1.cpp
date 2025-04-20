class Solution
{
public:
    int findDuplicate(vector<int> &arr)
    {
        unordered_map<int, int> mp;
        for (int a : arr)
        {
            mp[a]++;
            if (mp[a] > 1)
            {
                return a;
            }
        }
        return -1;
    }
};