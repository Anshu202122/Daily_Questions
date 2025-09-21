class Solution {
  public:
    vector<int> leftSmaller(vector<int>& heights) {
        int n = heights.size(), i = 1;
        vector<int> ans(n);
        stack<int> st;
        ans[0] = -1;
        st.push(0);
        for (int i = 1; i < n; i++) {
            while (!st.empty() && heights[i] <= heights[st.top()]) {
                st.pop();
            }
            if (st.empty()) {
                ans[i] = -1;
            } else {
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
    vector<int> rightSmaller(vector<int>& heights) {
        int n = heights.size(), i = 1;
        vector<int> ans(n);
        stack<int> st;
        ans[n - 1] = n;
        st.push(n - 1);
        for (int i = n - 2; i >= 0; i--) {
            while (!st.empty() && heights[i] <= heights[st.top()]) {
                st.pop();
            }
            if (st.empty()) {
                ans[i] = n;
            } else {
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), ans = 0;
        vector<int> left = leftSmaller(heights);
        vector<int> right = rightSmaller(heights);
        for (int i = 0; i < n; i++) {
            ans = max(ans, heights[i] * (right[i] - left[i] - 1));
        }
        return ans;
    }
    int maxArea(vector<vector<int>> &mat) {
        int n=mat.size(), m=mat[0].size(), ans=0;
        vector<int> height(m, 0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1){
                    height[j]++;
                }
                else{
                    height[j]=0;
                }
            }
            ans=max(ans, largestRectangleArea(height));
        }
        return ans;
    }
};
