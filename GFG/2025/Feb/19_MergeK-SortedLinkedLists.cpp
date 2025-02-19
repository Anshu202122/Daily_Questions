class Solution
{
public:
    #define p pair<int, Node *>
    Node *mergeKLists(vector<Node *> &arr)
    {
        Node *node = new Node(-1);
        priority_queue<p, vector<p>, greater<p>> pq;
        for (int i = 0; i < arr.size(); i++)
        {
            Node *temp = arr[i];
            pq.push({temp->data, temp});
        }
        Node *temp = node;
        while (!pq.empty())
        {
            Node *curr = pq.top().second;
            pq.pop();
            temp->next = curr;
            temp = temp->next;
            if (curr->next)
            {
                pq.push({curr->next->data, curr->next});
            }
        }
        return node->next;
    }
};