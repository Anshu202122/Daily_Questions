class Solution
{
public:
    Node *findFirstNode(Node *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return NULL;
        }
        unordered_map<Node *, int> mp;
        while (head)
        {
            if (mp.find(head) != mp.end())
            {
                return head;
            }
            mp[head]++;
            head = head->next;
        }
        return NULL;
    }
};