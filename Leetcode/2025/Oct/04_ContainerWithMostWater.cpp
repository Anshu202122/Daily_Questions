class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size(), i = 0, j = n - 1, ans = 0;
        while (i < j) {
            int l = min(height[i], height[j]);
            int b = j - i;
            ans = max(ans, l * b);
            if (height[i] > height[j]) {
                j--;
            } else {
                i++;
            }
        }
        return ans;
    }
};
