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

#include <queue>
#include <vector>

class Solution
{
public:
    ListNode *mergeKLists(std::vector<ListNode *> &lists)
    {
        auto comp = [](const ListNode *a, const ListNode *b) { return a->val > b->val; };
        std::priority_queue<ListNode *, std::vector<ListNode *>, decltype(comp)> pq(comp);
        ListNode *res = nullptr;
        ListNode *head = nullptr;

        for (int i = 0; i < lists.size(); i++) // O(n logn)
        {
            if (lists[i])
                pq.push(lists[i]);  // O(logn)
        }

        if (!pq.size()) // all list heads are null
        {
            return res;
        }

        while (pq.size())
        {
            if (res)
            {
                res->next = pq.top();
                res = res->next;
            }
            else
            {
                res = pq.top();
                head = res;
            }

            pq.pop();

            if (res->next)
            {
                pq.push(res->next);
                // res->next = nullptr;
            }
        }

        return head;
    }
};