class Solution
{
public:
    Node *split(Node *head)
    {
        Node *fast = head;
        Node *slow = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            if (fast != nullptr)
            {
                slow = slow->next;
            }
        }
        Node *temp = slow->next;
        slow->next = nullptr;
        return temp;
    }
    Node *merge(Node *first, Node *second)
    {
        if (first == nullptr)
            return second;
        if (second == nullptr)
            return first;
        if (first->data < second->data)
        {
            first->next = merge(first->next, second);
            return first;
        }
        else
        {
            second->next = merge(first, second->next);
            return second;
        }
    }
    Node *mergeSort(Node *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        Node *second = split(head);
        head = mergeSort(head);
        second = mergeSort(second);
        return merge(head, second);
    }
};