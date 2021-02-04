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
#include <vector>
#include <deque>
#include <queue>

class Solution
{
public:
    std::vector<int> levelOrder(TreeNode *root)
    {
        if (!root)
            return {};

        std::deque<TreeNode *> expand;
        std::vector<int> res;

        expand.push_back(root);
        while (!expand.empty())
        {
            TreeNode *cur = expand.front();
            expand.pop_front();

            res.push_back(cur->val);
            if (cur->left)
                expand.push_back(cur->left);
            if (cur->right)
                expand.push_back(cur->right);
        }

        return res;
    }
};