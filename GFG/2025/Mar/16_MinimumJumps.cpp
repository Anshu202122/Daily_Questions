class Solution
{
public:
    int minJumps(vector<int> &arr)
    {
        int n = arr.size(), maxi = 0, choice = 0, jumps = 0;
        for (int i = 0; i < n - 1; i++)
        {
            maxi = max(maxi, arr[i] + i);
            if (i == choice)
            {
                choice = maxi;
                jumps++;
            }
        }
        if (choice >= n - 1)
        {
            return jumps;
        }
        return -1;
    }
};