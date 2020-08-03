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
    ListNode *oddEvenList(ListNode *head)
    {
        ListNode *odd_pre = nullptr;
        ListNode *even_head = nullptr;
        ListNode *even_pre = nullptr;
        int count = 1;
        ListNode *cur = head;

        while (cur)
        {
            if (count % 2)
            {
                if (odd_pre)
                    odd_pre->next = cur;
                odd_pre = cur;
            }
            else
            {
                if (even_pre)
                    even_pre->next = cur;
                else
                    even_head = cur;
                even_pre = cur;
            }
            cur = cur->next;
            count++;
        }

        if (count % 2)
        {
            if (odd_pre)
                odd_pre->next = cur;
        }
        else
        {
            if (even_pre)
                even_pre->next = cur;
            else
                even_head = cur;
        }

        if (odd_pre)
            odd_pre->next = even_head;
        return head;
    }
};