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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        return mergeTwoListsV2(l1, l2);
    }

    ListNode *mergeTwoListsV2(ListNode *l1, ListNode *l2)
    {
        ListNode head;
        ListNode *cur = &head;
        while (l1 && l2)
        {
            ListNode *next = nullptr;
            if (l1->val <= l2->val)
            {
                next = l1->next;
                cur->next = l1;
                l1->next = nullptr;
                l1 = next;
            }
            else
            {
                next = l2->next;
                cur->next = l2;
                l2->next = nullptr;
                l2 = next;
            }
            cur = cur->next;
        }

        if (l1)
            cur->next = l1;
        if (l2)
            cur->next = l2;

        return head.next;
    }

    ListNode *mergeTwoListsV1(ListNode *l1, ListNode *l2)
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