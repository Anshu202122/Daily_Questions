class Solution
{
public:
    int compute(long curr, long next, int n)
    {
        int count = 0;
        while (curr <= n)
        {
            count += (next - curr);
            curr *= 10;
            next *= 10;
            next = min(next, long(n + 1));
        }
        return count;
    }
    int findKthNumber(int n, int k)
    {
        long curr = 1;
        k -= 1;
        while (k > 0)
        {
            int count = compute(curr, curr + 1, n);
            if (count <= k)
            {
                curr++;
                k -= count;
            }
            else
            {
                curr *= 10;
                k -= 1;
            }
        }
        return curr;
    }
};