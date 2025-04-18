class Trie
{
    struct TrieNode
    {
        TrieNode *child[26];
        bool isEnd;
        TrieNode()
        {
            isEnd = false;
            for (int i = 0; i < 26; i++)
            {
                child[i] = nullptr;
            }
        }
    };
public:
    TrieNode *root;
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string &word)
    {
        TrieNode *node = root;
        for (char ch : word)
        {
            int idx = ch - 'a';
            if (node->child[idx] == nullptr)
            {
                node->child[idx] = new TrieNode();
            }
            node = node->child[idx];
        }
        node->isEnd = true;
    }

    bool search(string &word)
    {
        TrieNode *node = root;
        for (char ch : word)
        {
            int idx = ch - 'a';
            if (node->child[idx] == nullptr)
            {
                return false;
            }
            node = node->child[idx];
        }
        return node->isEnd;
    }

    bool isPrefix(string &word)
    {
        TrieNode *node = root;
        for (char ch : word)
        {
            int idx = ch - 'a';
            if (node->child[idx] == nullptr)
            {
                return false;
            }
            node = node->child[idx];
        }
        return true;
    }
};