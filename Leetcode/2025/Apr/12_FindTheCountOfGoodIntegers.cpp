class Solution
{
public:
    long long countGoodIntegers(int n, int k)
    {
        unordered_set<string> st;
        int d = (n + 1) / 2;
        int start = pow(10, d - 1), end = pow(10, d) - 1;
        long long ans = 0;
        for (int i = start; i <= end; i++)
        {
            string left = to_string(i);
            string num = "";
            if (n % 2 == 0)
            {
                string right = left;
                reverse(right.begin(), right.end());
                num = left + right;
            }
            else
            {
                string right = left.substr(0, d - 1);
                reverse(right.begin(), right.end());
                num = left + right;
            }
            long long res = stoll(num);
            if (res % k != 0)
            {
                continue;
            }
            sort(num.begin(), num.end());
            st.insert(num);
        }
        vector<long long> factorial(11, 1);
        for (int i = 1; i < 11; i++)
        {
            factorial[i] = factorial[i - 1] * i;
        }
        for (const string &s : st)
        {
            vector<int> count(10, 0);
            for (const char &ch : s)
            {
                count[ch - '0']++;
            }
            int total = s.length();
            int zero = count[0];
            int nonzero = total - zero;
            long long perm(nonzero * factorial[total - 1]);
            for (int i = 0; i < 10; i++)
            {
                perm /= factorial[count[i]];
            }
            ans += perm;
        }
        return ans;
    }
};