class Solution
{
public:
    Node *cloneLinkedList(Node *head)
    {
        Node *temp = head;
        while (temp)
        {
            Node *node = new Node(temp->data);
            node->next = temp->next;
            temp->next = node;
            temp = node->next;
        }
        temp = head;
        Node *newHead = temp->next;
        while (temp)
        {
            if (temp->random == NULL)
            {
                temp->next->random = NULL;
            }
            else
            {
                temp->next->random = temp->random->next;
            }
            temp = temp->next->next;
        }
        temp = head;
        while (temp)
        {
            Node *temp2 = temp->next;
            temp->next = temp2->next;
            if (temp2->next)
            {
                temp2->next = temp2->next->next;
            }
            temp = temp->next;
        }
        return newHead;
    }
};