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
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *head = new ListNode(0);
        ListNode *res = head;
        ListNode *a = l1, *b = l2;

        int c = 0;
        int s = 0;
        while (a && b)
        {
            s = c + a->val + b->val;
            c = s / 10;
            res->next = new ListNode(s % 10);
            res = res->next;
            a = a->next;
            b = b->next;
        }

        ListNode *last = a ? a : b;
        while (last)
        {
            s = last->val + c;
            c = s / 10;
            res->next = new ListNode(s % 10);
            res = res->next;
            last = last->next;
        }

        if (c)
            res->next = new ListNode(1);

        res = head->next;
        delete head;
        return res;
    }
};