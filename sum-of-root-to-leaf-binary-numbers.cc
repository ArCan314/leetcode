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
    int _sumRootToLeaf(TreeNode *node, int cur)
    {
        if (!node->left && !node->right)
            return cur * 2 + node->val;
        int left = node->left ? _sumRootToLeaf(node->left, cur * 2 + node->val) : 0;
        int right = node->right ? _sumRootToLeaf(node->right, cur * 2 + node->val) : 0;
        return left + right;
    }

    int sumRootToLeaf(TreeNode *root)
    {
        if (!root)
            return 0;
        return _sumRootToLeaf(root, 0);
    }
};