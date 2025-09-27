class Solution {
public:
    int kBitFlips(vector<int>& arr, int k) {
        int n = arr.size(), ans = 0, cnt = 0;
        vector<bool> flip(n, false);
        for (int i = 0; i < n; i++) {
            if (i >= k && flip[i - k] == true) {
                cnt--;
            }
            if (cnt % 2 == arr[i]) {
                if (i + k > n) {
                    return -1;
                }
                cnt++;
                ans++;
                flip[i] = true;
            }
        }
        return ans;
    }
};
