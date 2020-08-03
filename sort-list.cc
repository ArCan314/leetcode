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
#include <algorithm>
#include <iostream>

class Solution
{
public:
    void _swap(ListNode *(&a_pre), ListNode *(&a), ListNode *(&b_pre), ListNode *(&b))
    {
        a_pre->next = b;
        b_pre->next = a;
        ListNode *temp = a->next;
        a->next = b->next;
        b->next = temp;
        std::swap(a, b);
    }

    void _sortList(ListNode *begin_pre, ListNode *begin, ListNode *end)
    {
        if (begin == end)
            return;

        ListNode *pivot = begin;
        ListNode *l = pivot;
        ListNode *l_pre = begin_pre;
        ListNode *r = pivot->next;
        ListNode *r_pre = pivot;

        while (r != end)
        {
            if (r->val < pivot->val)
            {
                l_pre = l;
                l = l->next;
                _swap(l_pre, l, r_pre, r);
            }
            r_pre = r;
            r = r->next;
        }
        print();
        std::cout << l_pre->val << ", " << l->val << ", " << r_pre->val << std::endl;
        _swap(begin_pre, pivot, l_pre, l);
        print();
        _sortList(begin_pre, pivot, l);
        _sortList(l, l->next, end);

    }

    void print()
    {
        auto temp = h;
        while (temp)
        {
            std::cout << temp->val << ",";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    ListNode *h;
    ListNode *sortList(ListNode *head)
    {
        ListNode head_append(0);
        h = &head_append;
        head_append.next = head;
        ListNode *end = head;
        while (end->next)
            end = end->next;
        _sortList(&head_append, head, nullptr);
        return head_append.next;
    }
};