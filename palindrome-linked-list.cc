struct ListNode {
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
// 1->2->3
// 1->2->3->4

class Solution
{
public:
    int getLen(ListNode *head)
    {
        int len = 0;
        ListNode *cur = head;
        while (cur)
        {
            len++;
            cur = cur->next;
        }
        return len;
    }

    void reverse(ListNode *head)
    {
        ListNode *cur = head->next, *pre = nullptr;
        while (cur)
        {
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        head->next = pre;
    }

    bool isPalindrome(ListNode *head)
    {
        if (!head)
            return true;
        int len = getLen(head);
        int forward_len = (len - 1) / 2;
        ListNode *mid = head;
        for (int i = 0; i < forward_len; i++)
            mid = mid->next;
        reverse(mid);

        ListNode *a, *b;
        a = head;
        b = mid->next;
        
        bool res = true;
        while (b)
        {
            if (a->val != b->val)
            {
                res = false;
                break;
            }
            a = a->next;
            b = b->next;
        }
        return res;
    }
};