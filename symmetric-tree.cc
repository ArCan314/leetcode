struct TreeNode {
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
class Solution {
private: 
    bool _isStmmetric(TreeNode *l, TreeNode *r)
    {
        if (l && r)
        {
            if (l->val == r->val)
            {
                return _isStmmetric(l->left, r->right) && _isStmmetric(l->right, r->left);
            }
            else
                return false;
        }
        else if (!l && !r)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

public:
    bool isSymmetric(TreeNode* root) 
    {
        if (root)
        {
            return _isStmmetric(root->left, root->right);
        }
        else
        {
            return false;
        }
    }
};