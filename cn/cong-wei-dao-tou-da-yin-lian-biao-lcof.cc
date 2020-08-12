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

#include <vector>
#include <algorithm>

class Solution
{
public:
    std::vector<int> reversePrint(ListNode *head)
    {
        std::vector<int> res;
        ListNode *cur = head;
        while (cur)
        {
            res.push_back(cur->val);
            cur = cur->next;
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};