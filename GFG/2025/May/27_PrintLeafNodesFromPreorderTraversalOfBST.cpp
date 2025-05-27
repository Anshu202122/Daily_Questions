class Solution
{
public:
    vector<int> leafNodes(vector<int> &preorder)
    {
        int n = preorder.size();
        vector<int> ans;
        stack<int> st;
        st.push(preorder[0]);
        for (int i = 1; i < n; i++)
        {
            if (st.top() > preorder[i])
            {
                st.push(preorder[i]);
            }
            else
            {
                int temp = st.top(), count = 0;
                while (!st.empty() && st.top() < preorder[i])
                {
                    st.pop();
                    count++;
                }
                st.push(preorder[i]);
                if (count >= 2)
                {
                    ans.push_back(temp);
                }
            }
        }
        ans.push_back(st.top());
        return ans;
    }
};