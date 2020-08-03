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
#include <optional>
#include <numeric>
#include <iostream>
#include <functional>

class Solution
{
public:
    int max = std::numeric_limits<int>::min();
    int _maxPathSum(TreeNode *root)
    {
        if (!root)
            return 0;
        auto lval = std::max(_maxPathSum(root->left), 0);
        auto rval = std::max(_maxPathSum(root->right), 0);
        max = std::max(max, root->val + lval + rval);
        return root->val + std::max(std::max(lval, 0), std::max(rval, 0));
    }

    int maxPathSum(TreeNode *root)
    {
        _maxPathSum(root);
        return max;
    }
};