#define LOCAL
#ifdef LOCAL

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

#endif // LOCAL

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
    ListNode *reverseList(ListNode *head)
    {
        if (!head)
            return nullptr;

        ListNode *cur = head, *pre = nullptr, *next = head->next;

        while (next)
        {
            cur->next = pre;

            pre = cur;
            cur = next;
            next = next->next;
        }

        cur->next = pre;

        return cur;
    }
};