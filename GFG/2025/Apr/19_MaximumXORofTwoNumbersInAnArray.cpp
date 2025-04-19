class Solution
{
public:
    int maxXor(vector<int> &arr)
    {
        int ans = 0, mask = 0;
        unordered_set<int> s;
        for (int i = 30; i >= 0; i--)
        {
            mask |= (1 << i);
            for (auto a : arr)
            {
                s.insert(a & mask);
            }
            int cur = ans | (1 << i);
            for (int m : s)
            {
                if (s.count(cur ^ m))
                {
                    ans = cur;
                    break;
                }
            }
            s.clear();
        }
        return ans;
    }
};