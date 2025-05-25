class Solution
{
public:
    bool pythagoreanTriplet(vector<int> &arr)
    {
        int n = arr.size();
        unordered_set<int> st;
        for (int a : arr)
        {
            st.insert(a * a);
        }
        for (int i = 0; i < n; i++)
        {
            int a = arr[i];
            for (int j = i + 1; j < n; j++)
            {
                int b = arr[j];
                if (st.find((a * a) + (b * b)) != st.end())
                {
                    return true;
                }
            }
        }
        return false;
    }
};