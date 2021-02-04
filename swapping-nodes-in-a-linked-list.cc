struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <algorithm>

class Solution
{
public:
    int getLen(ListNode *head)
    {
        int len = 0;
        while (head)
        {
            len++;
            head = head->next;
        }
        return len;
    }

    ListNode *swapNodes(ListNode *head, int k)
    {
        int ind_a = k, ind_b = getLen(head) - k + 1;

        ListNode *a, *b;
        a = b = head;

        int cur = 1;
        while (cur++ != ind_a)
            a = a->next;
        
        cur = 1;
        while (cur++ != ind_b)
            b = b->next;

        std::swap(a->val, b->val);
        return head;
    }
};