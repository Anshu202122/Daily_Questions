class Solution
{
public:
    int countConsec(int n)
    {
        if (n == 2)
        {
            return 1;
        }
        int prev = 0, curr = 1, ans = 1, next = 0;
        for (int i = 3; i <= n; i++)
        {
            next = prev + curr;
            ans = (2 * ans) + next;
            prev = curr;
            curr = next;
        }
        return ans;
    }
};