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
    ListNode *getKthFromEnd(ListNode *head, int k)
    {
        ListNode *forward = head;
        int count = 0;
        while (forward && count++ < k)
            forward = forward->next;

        if (count != k)
            return nullptr;

        ListNode *res = head;
        while (forward)
        {
            res = res->next;
            forward = forward->next;
        }

        return res;
    }
};