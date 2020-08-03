#include <vector>
#include <deque>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    std::vector<std::vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        if (!root)
            return {};

        std::deque<TreeNode *> node_queue;
        std::vector<std::vector<int>> res;
        node_queue.push_back(root);
        int height = 0;
        while (!node_queue.empty())
        {
            std::deque<TreeNode *> temp;
            res.emplace_back();

            while (!node_queue.empty())
            {
                TreeNode *cur;
                if (height % 2)
                {
                    cur = node_queue.back();
                    node_queue.pop_back();
                    if (cur->right)
                        temp.push_front(cur->right);
                    if (cur->left)
                        temp.push_front(cur->left);
                }
                else
                {
                    cur = node_queue.front();
                    node_queue.pop_front();
                    if (cur->left)
                        temp.push_back(cur->left);
                    if (cur->right)
                    temp.push_back(cur->right);
                }
                res.back().push_back(cur->val);
            }
            node_queue.swap(temp);
            height++;
        }
        return res;
    }
};