class Solution
{
public:
    void update(int i, int l, int r, int idx, vector<long long> &seg)
    {
        if (l == r)
        {
            seg[i] = 1;
            return;
        }
        int mid = l + (r - l) / 2;
        if (idx <= mid)
        {
            update(2 * i + 1, l, mid, idx, seg);
        }
        else
        {
            update(2 * i + 2, mid + 1, r, idx, seg);
        }
        seg[i] = seg[2 * i + 1] + seg[2 * i + 2];
    }
    long long query(int qs, int qe, int i, int l, int r, vector<long long> &seg)
    {
        if (r < qs || l > qe)
        {
            return 0;
        }
        if (l >= qs && r <= qe)
        {
            return seg[i];
        }
        int mid = l + (r - l) / 2;
        long long left = query(qs, qe, 2 * i + 1, l, mid, seg);
        long long right = query(qs, qe, 2 * i + 2, mid + 1, r, seg);
        return left + right;
    }
    long long goodTriplets(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[nums2[i]] = i;
        }
        vector<long long> seg(4 * n);
        long long ans = 0;
        update(0, 0, n - 1, mp[nums1[0]], seg);
        for (int i = 1; i < n; i++)
        {
            int idx = mp[nums1[i]];
            long long leftCommon = query(0, idx, 0, 0, n - 1, seg);
            long long notCommon = i - leftCommon;
            long long ele = (n - 1) - idx;
            long long rightCommon = ele - notCommon;
            ans += leftCommon * rightCommon;
            update(0, 0, n - 1, idx, seg);
        }
        return ans;
    }
};