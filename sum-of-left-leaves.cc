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

class Solution
{
public:
    int _sumOfLeftLeaves(TreeNode *node, bool is_left)
    {
        if (!node->left && !node->right)
            return is_left ? node->val : 0;
        
        int sum = 0;
        if (node->left)
            sum += _sumOfLeftLeaves(node->left, true);
        if (node->right)
            sum += _sumOfLeftLeaves(node->right, false);
        return sum;
    }

    int sumOfLeftLeaves(TreeNode *root)
    {
        if (!root)
            return 0;
        return _sumOfLeftLeaves(root, false);
    }
};