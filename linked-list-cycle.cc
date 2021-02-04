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
#include <unordered_set>

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        return hasCycleTwoPointer(head);
    }

    bool hasCycleHashTable(ListNode *head)
    {
        std::unordered_set<ListNode *> visit;
        while (head && visit.insert(head).second)
            head = head->next;
        return head;
    }

    bool hasCycleTwoPointer(ListNode *head)
    {
        ListNode *slow = head, *fast = head;
        while (fast)
        {
            slow = slow->next;
            fast = fast->next;
            if (fast)
                fast = fast->next;
            if (slow == fast)
                break;
        }
        return fast;
    }
};