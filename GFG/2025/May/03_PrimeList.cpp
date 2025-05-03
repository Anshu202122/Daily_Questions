class Solution
{
public:
    bool prime(int n)
    {
        if (n <= 1)
        {
            return false;
        }
        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                return false;
            }
        }
        return true;
    }
    int nextPrime(int n)
    {
        if (prime(n))
        {
            return n;
        }
        int prev = n - 1, next = n + 1;
        while (true)
        {
            if (prev >= 2 && prime(prev))
            {
                return prev;
            }
            if (prime(next))
            {
                return next;
            }
            --prev;
            ++next;
        }
    }
    Node *primeList(Node *head)
    {
        Node *temp = head;
        while (temp)
        {
            int n = temp->val;
            temp->val = nextPrime(n);
            temp = temp->next;
        }
        return head;
    }
};