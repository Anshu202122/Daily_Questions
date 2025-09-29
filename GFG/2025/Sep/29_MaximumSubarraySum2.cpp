class Solution {
public:
    int maxSubarrSum(vector<int>& arr, int a, int b) {
        int n = arr.size(), ans = 0;
        deque<int> dq;
        for (int i = 1; i < n; i++) {
            arr[i] += arr[i - 1];
        }
        ans = arr[a - 1];
        dq.push_back(0);
        for (int i = a; i < n; i++) {
            if (i - b - 1 >= 0) {
                if (dq.front() == arr[i - b - 1]) {
                    dq.pop_front();
                }
            } else if (i - b == 0) {
                if (dq.front() == 0) {
                    dq.pop_front();
                }
            }
            while (!dq.empty() && dq.back() > arr[i - a]) {
                dq.pop_back();
            }
            dq.push_back(arr[i - a]);
            ans = max(ans, arr[i] - dq.front());
        }
        return ans;
    }
};
