class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution
{
public:
    void _connect(Node *node, Node *parent, bool is_left)
    {
        if (!node)
            return;

        node->next = node->right;
        _connect(node->left, node, true);
        if (is_left && parent)
        {
            node->next = parent->next;
        }
        else if (!is_left && parent)
        {
            if (parent->next)
                node->next = parent->next->left;
            else
                node->next = nullptr;
        }
        else
        {
            node->next = nullptr;
        }
        _connect(node->right, node, false);
    }

    Node *connect(Node *root)
    {
        _connect(root, nullptr, true);
        return root;
    }
};