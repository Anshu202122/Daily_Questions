class LRUCache
{
private:
    struct Node
    {
        int key, value;
        Node *next;
        Node *prev;
        Node(int k, int val)
        {
            key = k;
            value = val;
            next = NULL;
            prev = NULL;
        }
    };

public:
    // Constructor for initializing the cache capacity with the given value.
    int cap;
    unordered_map<int, Node *> mp;
    Node *head;
    Node *tail;
    LRUCache(int cap)
    {
        this->cap = cap;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    // Function to return value corresponding to the key.
    int get(int key)
    {
        if (mp.find(key) == mp.end())
        {
            return -1;
        }
        Node *node = mp[key];
        remove(node);
        add(node);
        return node->value;
    }

    // Function for storing key-value pair.
    void put(int key, int value)
    {
        if (mp.find(key) != mp.end())
        {
            Node *node = mp[key];
            remove(node);
            delete node;
        }
        Node *node = new Node(key, value);
        mp[key] = node;
        add(node);
        if (mp.size() > cap)
        {
            Node *del = tail->prev;
            remove(del);
            mp.erase(del->key);
            delete del;
        }
    }
    void add(Node *node)
    {
        Node *nextNode = head->next;
        head->next = node;
        node->prev = head;
        node->next = nextNode;
        nextNode->prev = node;
    }
    void remove(Node *node)
    {
        Node *prevNode = node->prev;
        Node *nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }
};