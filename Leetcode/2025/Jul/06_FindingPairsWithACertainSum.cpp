class FindSumPairs
{
public:
    vector<int> vec1, vec2;
    unordered_map<int, int> mp;
    FindSumPairs(vector<int> &nums1, vector<int> &nums2)
    {
        vec1 = nums1;
        vec2 = nums2;
        for (int num : nums2)
        {
            mp[num]++;
        }
    }

    void add(int index, int val)
    {
        mp[vec2[index]]--;
        vec2[index] += val;
        mp[vec2[index]]++;
    }

    int count(int tot)
    {
        int ans = 0;
        for (int num : vec1)
        {
            if (mp.find(tot - num) != mp.end())
            {
                ans += mp[tot - num];
            }
        }
        return ans;
    }
};