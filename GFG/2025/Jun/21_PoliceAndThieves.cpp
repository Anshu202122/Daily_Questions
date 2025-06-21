class Solution
{
public:
    int catchThieves(vector<char> &arr, int k)
    {
        int n = arr.size(), count = 0, p = 0, t = 0;
        while (p < n && arr[p] != 'P')
        {
            p++;
        }
        while (t < n && arr[t] != 'T')
        {
            t++;
        }
        while (p < n && t < n)
        {
            if (abs(p - t) <= k)
            {
                count++;
                p++;
                t++;
            }
            else if (p < t)
            {
                p++;
            }
            else if (t < p)
            {
                t++;
            }
            while (p < n && arr[p] != 'P')
            {
                p++;
            }
            while (t < n && arr[t] != 'T')
            {
                t++;
            }
        }
        return count;
    }
};