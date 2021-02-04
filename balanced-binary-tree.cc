struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <cmath>
#include <algorithm>

class Solution
{
public:
    int isBalancedImpl(TreeNode *node)
    {
        if (!node)
            return 0;

        auto left = isBalancedImpl(node->left);
        auto right = isBalancedImpl(node->right);
        
        if (left == -1 || right == -1)
            return -1;
        
        return (std::abs(left - right) > 1) ? -1 : (std::max(left, right) + 1);
    }

    bool isBalanced(TreeNode *root)
    {
        return isBalancedImpl(root) != -1;
    }
};