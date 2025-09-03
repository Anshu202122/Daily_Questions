class Solution
{
public:
    Node *reverse(Node *head)
    {
        Node *previous = NULL;
        Node *temp = head;
        while (temp != NULL)
        {
            Node *nextP = NULL;
            if (temp->next != NULL)
            {
                nextP = temp->next;
            }
            temp->prev = nextP;
            temp->next = previous;
            previous = temp;
            temp = nextP;
        }
        return previous;
    }
};