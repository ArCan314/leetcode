#define LOCAL
#ifdef LOCAL
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
#endif

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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *l3 = nullptr;
        ListNode *head = l3;

        while (l1 && l2)
        {
            if (l1->val <= l2->val)
            {
                if (l3 == nullptr)
                {
                    l3 = l1;
                    head = l3;
                }
                else
                {
                    l3->next = l1;
                    l3 = l3->next;
                }

                l1 = l1->next;
                l3->next = nullptr;
            }
            else
            {
                if (l3 == nullptr)
                {
                    l3 = l2;
                    head = l3;
                }
                else
                {
                    l3->next = l2;
                    l3 = l3->next;
                }

                l2 = l2->next;
                l3->next = nullptr;
            }
        }

        while (l1)
        {
            if (l3 == nullptr)
            {
                l3 = l1;
                head = l3;
            }
            else
            {
                l3->next = l1;
                l3 = l3->next;
            }

            l1 = l1->next;
            l3->next = nullptr;
        }

        while (l2)
        {
            if (l3 == nullptr)
            {
                l3 = l2;
                head = l3;
            }
            else
            {
                l3->next = l2;
                l3 = l3->next;
            }

            l2 = l2->next;
            l3->next = nullptr;
        }

        return head;
    }
};