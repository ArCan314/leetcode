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
        if (!head)
            return nullptr;

        Node *new_list_head = new Node(head->val), *cur;
        std::unordered_map<Node *, Node *> exist;
        exist[head] = new_list_head;

        cur = new_list_head;
        while (head)
        {
            if (head->random)
            {
                if (exist.count(head->random))
                {
                    cur->random = exist[head->random];
                }
                else
                {
                    cur->random = new Node(head->random->val);
                    exist[head->random] = cur->random;
                }
            }

            if (head->next)
            {
                if (exist.count(head->next))
                {
                    cur->next = exist.at(head->next);
                }
                else
                {
                    cur->next = new Node(head->next->val);
                    exist[head->next] = cur->next;
                }
            }

            head = head->next;
            cur = cur->next;
        }

        return new_list_head;
    }
};