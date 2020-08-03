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
    TreeNode *_flatten(TreeNode *root)
    {
        if (!root->left && !root->right)
            return root;

        TreeNode *reach = nullptr;
        if (root->left)
        {
            TreeNode *right = root->right;
            root->right = root->left;
            root->left = nullptr;
            reach = _flatten(root->right);

            if (reach && right)
            {
                reach->right = right;
                reach = _flatten(reach->right);
            }
        }
        else if (root->right)
        {
            reach = _flatten(root->right);
        }

        return reach;
    }

public:
    void flatten(TreeNode *root)
    {
        if (!root)
            return;

        _flatten(root);
    }
};