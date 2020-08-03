#include <algorithm>

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
private:
    int res = 0;
    int _diameterOfBinaryTree(TreeNode *root) noexcept
    {
        if (root)
        {
            int left = _diameterOfBinaryTree(root->left);
            int right = _diameterOfBinaryTree(root->right);

            if (left + right > res)
                res = left + right;

            return std::max(left, right) + 1;
        }
        else
        {
            return 0;
        }
    }

public:
    int diameterOfBinaryTree(TreeNode *root) noexcept
    {
        res = 0;
        _diameterOfBinaryTree(root);
        return res;
    }
};