class Solution
{
public:
    bool isPal(string s)
    {
        int i = 0, j = s.length() - 1;
        while (i <= j)
        {
            if (s[i] != s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    string solve(long long num, int k)
    {
        if (num == 0)
        {
            return "0";
        }
        string ans = "";
        while (num > 0)
        {
            ans += to_string(num % k);
            num /= k;
        }
        return ans;
    }
    long long kMirror(int k, int n)
    {
        long long sum = 0;
        int l = 1;
        while (n > 0)
        {
            int half = (l + 1) / 2;
            long long minNum = pow(10, half - 1);
            long long maxNum = pow(10, half) - 1;
            for (int i = minNum; i <= maxNum; i++)
            {
                string first = to_string(i);
                string second = first;
                reverse(second.begin(), second.end());
                string ans = "";
                if (l % 2 == 0)
                {
                    ans = first + second;
                }
                else
                {
                    ans = first + second.substr(1);
                }
                long long num = stoll(ans);
                string baseK = solve(num, k);
                if (isPal(baseK))
                {
                    sum += num;
                    n--;
                    if (n == 0)
                    {
                        break;
                    }
                }
            }
            l++;
        }
        return sum;
    }
};