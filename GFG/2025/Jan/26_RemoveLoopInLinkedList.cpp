class Solution
{
public:
    // Function to remove a loop in the linked list.
    void removeLoop(Node *head)
    {
        unordered_map<Node *, int> mp;
        Node *temp = head;
        while (temp)
        {
            if (mp.find(temp->next) != mp.end())
            {
                temp->next = NULL;
                break;
            }
            mp[temp]++;
            temp = temp->next;
        }
    }
};