class Solution
{
public:
    Node *reverseKGroup(Node *head, int k)
    {
        int n = 1;
        Node *prev = NULL;
        Node *curr = head;
        Node *nextNode = NULL;
        while (curr && n <= k)
        {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
            n++;
        }
        if (nextNode)
        {
            head->next = reverseKGroup(nextNode, k);
        }
        return prev;
    }
};