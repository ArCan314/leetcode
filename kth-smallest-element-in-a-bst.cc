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
    bool _kthSmallest(TreeNode *node, int k, int &ind, int &res)
    {
        if (!node)
        return false;
        
        bool is_find = _kthSmallest(node->left, k, ind, res);
        if (is_find)
            return true;

        if (++ind == k)
        {
            res = node->val;
            return true;
        }

        is_find = _kthSmallest(node->right, k, ind, res);
        if (is_find)
            return true;
        else 
            return false;
    }

    int kthSmallest(TreeNode *root, int k)
    {
        int ind = 0, res;
        _kthSmallest(root, k, ind, res);
        return res;
    }
};