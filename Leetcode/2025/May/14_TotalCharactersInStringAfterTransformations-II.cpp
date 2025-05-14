class Solution
{
public:
    typedef vector<vector<int>> Matrix;
    int m = 1e9 + 7;
    Matrix multiply(Matrix &a, Matrix &b)
    {
        Matrix ans(26, vector<int>(26, 0));
        for (int i = 0; i < 26; i++)
        {
            for (int j = 0; j < 26; j++)
            {
                for (int k = 0; k < 26; k++)
                {
                    ans[i][j] = (ans[i][j] + (1LL * a[i][k] * b[k][j]) % m) % m;
                }
            }
        }
        return ans;
    }
    Matrix exponentiation(Matrix &base, int expo)
    {
        if (expo == 0)
        {
            Matrix I(26, vector<int>(26, 0));
            for (int i = 0; i < 26; i++)
            {
                I[i][i] = 1;
            }
            return I;
        }
        Matrix half = exponentiation(base, expo / 2);
        Matrix ans = multiply(half, half);
        if (expo % 2 == 1)
        {
            ans = multiply(ans, base);
        }
        return ans;
    }
    int lengthAfterTransformations(string s, int t, vector<int> &nums)
    {
        int n = s.length();
        vector<int> freq(26, 0);
        for (char &ch : s)
        {
            freq[ch - 'a']++;
        }
        Matrix T(26, vector<int>(26, 0));
        for (int i = 0; i < 26; i++)
        {
            for (int j = 1; j <= nums[i]; j++)
            {
                T[(i + j) % 26][i]++;
            }
        }
        Matrix ans = exponentiation(T, t);
        vector<int> newFreq(26, 0);
        for (int i = 0; i < 26; i++)
        {
            for (int j = 0; j < 26; j++)
            {
                newFreq[i] = (newFreq[i] + (1LL * ans[i][j] * freq[j]) % m) % m;
            }
        }
        int len = 0;
        for (int i = 0; i < 26; i++)
        {
            len = (len + newFreq[i]) % m;
        }
        return len;
    }
};