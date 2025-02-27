class Solution
{
public:
    stack<int> st;
    int num;
    Solution()
    {
        num = -1;
    }

    // Add an element to the top of Stack
    void push(int x)
    {
        if (st.empty())
        {
            num = x;
            st.push(x);
        }
        else if (x < num)
        {
            st.push(2 * x - num);
            num = x;
        }
        else
        {
            st.push(x);
        }
    }

    // Remove the top element from the Stack
    void pop()
    {
        if (st.empty())
        {
            return;
        }
        int top = st.top();
        st.pop();
        if (top < num)
        {
            num = 2 * num - top;
        }
    }

    // Returns top element of the Stack
    int peek()
    {
        if (st.empty())
        {
            return -1;
        }
        int top = st.top();
        return (num > top) ? num : top;
    }

    // Finds minimum element of Stack
    int getMin()
    {
        if (st.empty())
        {
            return -1;
        }
        return num;
    }
};