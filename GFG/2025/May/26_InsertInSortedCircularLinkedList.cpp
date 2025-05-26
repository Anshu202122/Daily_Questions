class Solution
{
public:
    Node *sortedInsert(Node *head, int data)
    {
        Node *node = new Node(data);
        Node *temp = head;
        if (!head)
        {
            return node;
        }
        if (head->data > data)
        {
            node->next = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = node;
            return node;
        }
        while (temp->next != head && temp->next->data <= data)
        {
            temp = temp->next;
        }
        node->next = temp->next;
        temp->next = node;
        return head;
    }
};