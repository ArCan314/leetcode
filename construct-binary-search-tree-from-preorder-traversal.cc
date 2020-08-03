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

class Solution
{
public:
    void _bstFromPreorder(TreeNode *(&node), std::vector<int> &preorder, int l, int r)
    {
        if (l >= r)
            return;
        
        node = new TreeNode(preorder[l]);
        int lc = l + 1, rc = l + 1;
        while (lc < r)
            if (preorder[lc] < node->val)
                break;
            else
                lc++;
        while (rc < r)
            if (preorder[rc] > node->val)
                break;
            else
                rc++;

        _bstFromPreorder(node->left, preorder, lc, rc);
        _bstFromPreorder(node->right, preorder, rc, r);
    }

    TreeNode *bstFromPreorder(std::vector<int> &preorder)
    {
        TreeNode *root = nullptr;
        _bstFromPreorder(root, preorder, 0, preorder.size());
        return root;
    }
};