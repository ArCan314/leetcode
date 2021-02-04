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
    bool isSymmetricImpl(TreeNode *node_a, TreeNode *node_b)
    {
        if (!node_a && !node_b)
            return true;

        if (node_a && node_b && node_a->val == node_b->val)
        {
            bool res = isSymmetricImpl(node_a->left, node_b->right);
            if (res)
                res = isSymmetricImpl(node_a->right, node_b->left);
            return res;
        }
        else
            return false;
    }

    bool isSymmetric(TreeNode *root)
    {
        if (!root)
            return true;
        return isSymmetricImpl(root->left, root->right);
    }
};