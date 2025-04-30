class Solution
{
public:
    int countNodesinLoop(Node *head)
    {
        Node *temp = head;
        set<Node *> st;
        int ans = 0;
        while (temp)
        {
            if (st.find(temp) != st.end())
            {
                Node *node = temp;
                do
                {
                    ans++;
                    temp = temp->next;
                } while (temp != node);
                return ans;
            }
            st.insert(temp);
            temp = temp->next;
        }
        return 0;
    }
};