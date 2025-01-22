class Solution
{
public:
    Node *reverse(Node *head)
    {
        Node *curr = head;
        Node *prev = NULL;
        Node *nextNode = NULL;
        while (curr)
        {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
    Node *trim(Node *head)
    {
        while (head->next != NULL && head->data == 0)
        {
            head = head->next;
        }
        return head;
    }
    Node *addTwoLists(Node *num1, Node *num2)
    {
        int carry = 0;
        Node *ans = NULL;
        Node *curr = NULL;
        num1 = trim(num1);
        num2 = trim(num2);
        num1 = reverse(num1);
        num2 = reverse(num2);
        while (num1 != NULL || num2 != NULL || carry != 0)
        {
            int sum = carry;
            if (num1 != NULL)
            {
                sum += num1->data;
                num1 = num1->next;
            }
            if (num2 != NULL)
            {
                sum += num2->data;
                num2 = num2->next;
            }
            Node *newNode = new Node(sum % 10);
            carry = sum / 10;
            if (ans == NULL)
            {
                ans = newNode;
                curr = newNode;
            }
            else
            {
                curr->next = newNode;
                curr = curr->next;
            }
        }
        return reverse(ans);
    }
};