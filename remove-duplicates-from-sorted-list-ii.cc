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
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode sentinel_head;
        sentinel_head.next = head;

        ListNode *cur = head, *pre = &sentinel_head;

        while (cur && cur->next)
        {
            if (cur->val == cur->next->val)
            {
                int temp_val = cur->val;
                while (cur && cur->val == temp_val)
                {
                    ListNode *next = cur->next;
                    delete cur;
                    cur = next;
                }
                pre->next = cur;
            }
            else
            {
                pre = cur;
                cur = cur->next;
            }
        }
        return sentinel_head.next;
    }
};