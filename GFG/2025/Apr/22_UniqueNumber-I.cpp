class Solution
{
public:
    int findUnique(vector<int> &arr)
    {
        int x = 0;
        for (int a : arr)
        {
            x ^= a;
        }
        return x;
    }
};