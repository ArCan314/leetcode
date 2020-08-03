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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *forward = head, *cur = head, *pre = nullptr;

        for (int i = 0; i < n; i++)
        {
            forward = forward->next;
        }

        while (forward)
        {
            forward = forward->next;
            pre = cur;
            cur = cur->next;
        }

        if (pre)
            pre->next = cur->next;
        else
        {
            head = cur->next;
        }
        delete cur;
        return head;
    }
};