class Solution
{
public:
    void build(int i, int l, int r, vector<int> &baskets, vector<int> &seg)
    {
        if (l == r)
        {
            seg[i] = baskets[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * i + 1, l, mid, baskets, seg);
        build(2 * i + 2, mid + 1, r, baskets, seg);
        seg[i] = max(seg[2 * i + 1], seg[2 * i + 2]);
    }
    bool query(int i, int l, int r, vector<int> &seg, int fruit)
    {
        if (seg[i] < fruit)
        {
            return false;
        }
        if (l == r)
        {
            seg[i] = -1;
            return true;
        }
        int mid = (l + r) / 2;
        bool placed = false;
        if (seg[2 * i + 1] >= fruit)
        {
            placed = query(2 * i + 1, l, mid, seg, fruit);
        }
        else
        {
            placed = query(2 * i + 2, mid + 1, r, seg, fruit);
        }
        seg[i] = max(seg[2 * i + 1], seg[2 * i + 2]);
        return placed;
    }
    int numOfUnplacedFruits(vector<int> &fruits, vector<int> &baskets)
    {
        int n = fruits.size(), count = 0;
        vector<int> segTree(4 * n, -1);
        build(0, 0, n - 1, baskets, segTree);
        for (int &fruit : fruits)
        {
            if (!query(0, 0, n - 1, segTree, fruit))
            {
                count++;
            }
        }
        return count;
    }
};