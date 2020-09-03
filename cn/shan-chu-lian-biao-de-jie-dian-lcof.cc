struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *deleteNode(ListNode *head, int val)
    {
        if (!head)
            return nullptr;

        ListNode *cur = head, *pre = nullptr;

        while (cur)
        {
            if (cur->val == val)
                break;
            
            pre = cur;
            cur = cur->next;
        }

        if (!pre) // delete head node
            head = cur->next;
        else if (cur)
            pre->next = cur->next;
            
        return head;
    }
};