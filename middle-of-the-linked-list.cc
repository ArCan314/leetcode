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
    ListNode *middleNode(ListNode *head)
    {
        ListNode temp(0);
        temp.next = head;
        ListNode *slow = &temp, *fast = &temp;
        bool is_fin = false;
        while (!is_fin)
        {
            slow = slow->next;

            for (int i = 0; i < 2; i++)
            {
                if (fast->next)
                {
                    fast = fast->next;
                }
                else
                {
                    is_fin = true;
                    break;
                }
            }
        }

        return slow;
    }
};