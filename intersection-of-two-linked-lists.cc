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
    int getLength(ListNode *head) const noexcept
    {
        int length = 0;
        while (head)
        {
            head = head->next;
            length++;
        }
        return length;
    }

    int getLengthRec(ListNode *head) const noexcept
    {
        if (!head)
            return 0;

        return getLengthRec(head->next) + 1;
    }

    ListNode *getIntersectionNode(ListNode *head_a, ListNode *head_b) const noexcept
    {
        if (!head_a || !head_b)
        {
            return nullptr;
        }

        int len_a = getLength(head_a);
        int len_b = getLength(head_b);
        ListNode *target = nullptr;

        if (len_a < len_b)
        {
            for (int i = len_b - len_a; i > 0; i--) // len_b > len_a
            {
                head_b = head_b->next;
            }
        }
        else
        {
            for (int i = len_a - len_b; i > 0; i--)
            {
                head_a = head_a->next;
            }
        }
        
        while (head_a)
        {
            if (head_a == head_b)
            {
                target = head_a;
                break;
            }

            head_a = head_a->next;
            head_b = head_b->next;
        }

        return target;
    }
};
