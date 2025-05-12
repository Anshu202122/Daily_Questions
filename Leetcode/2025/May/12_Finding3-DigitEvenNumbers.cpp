class Solution
{
public:
    vector<int> findEvenNumbers(vector<int> &digits)
    {
        int n = digits.size();
        set<int> st;
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    if (i == j || i == k || j == k)
                    {
                        continue;
                    }
                    int num = digits[i] * 100 + digits[j] * 10 + digits[k];
                    if (num >= 100 && num % 2 == 0)
                    {
                        st.insert(num);
                    }
                }
            }
        }
        for (auto it : st)
        {
            ans.push_back(it);
        }
        return ans;
    }
};