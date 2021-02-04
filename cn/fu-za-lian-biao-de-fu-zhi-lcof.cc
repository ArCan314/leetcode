class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
#include <unordered_map>

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        Node p_head(0);
        Node *cur = &p_head, *other_cur = head;
        std::unordered_map<Node *, Node *> node_map;

        while (other_cur)
        {
            cur->next = new Node(other_cur->val);
            cur = cur->next;
            node_map[other_cur] = cur;
            other_cur = other_cur->next;
        }

        cur = p_head.next, other_cur = head;
        while (other_cur)
        {
            if (const auto iter = node_map.find(other_cur->random); iter != node_map.end())
                cur->random = iter->second;
            cur = cur->next;
            other_cur = other_cur->next;
        }

        return p_head.next;
    }
};