class Solution
{
public:
    int missingNumber(vector<int> &arr)
    {
        int i = 1, maxNum = 0;
        set<int> st;
        for (int a : arr)
        {
            st.insert(a);
            maxNum = max(maxNum, a);
        }
        if (maxNum <= 0)
        {
            return 1;
        }
        while (i <= maxNum)
        {
            if (st.find(i) == st.end())
            {
                return i;
            }
            i++;
        }
        return i;
    }
};