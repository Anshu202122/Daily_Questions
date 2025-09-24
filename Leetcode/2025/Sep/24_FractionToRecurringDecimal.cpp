class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string ans = "";
        if (numerator == 0) {
            return "0";
        }
        if ((long long)numerator * (long long)denominator < 0) {
            ans += '-';
        }
        long long absNum = labs(numerator);
        long long absDen = labs(denominator);
        long long div = absNum / absDen;
        ans += to_string(div);
        long long rem = absNum % absDen;
        if (rem == 0) {
            return ans;
        }
        ans += '.';
        unordered_map<int, int> mp;
        while (rem != 0) {
            if (mp.count(rem)) {
                ans.insert(mp[rem], "(");
                ans += ')';
                break;
            }
            mp[rem] = ans.length();
            rem *= 10;
            int digit = rem / absDen;
            ans += to_string(digit);
            rem %= absDen;
        }
        return ans;
    }
};
