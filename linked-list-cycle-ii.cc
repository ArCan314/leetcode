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
#include <unordered_set>

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        return detectCycleHashTable(head);
    }

    ListNode *detectCycleHashTable(ListNode *head)
    {
        ListNode *cur = head;
        std::unordered_set<ListNode *> visited;
        while (cur && visited.insert(cur).second)
            cur = cur->next;
        return cur;
    }
};