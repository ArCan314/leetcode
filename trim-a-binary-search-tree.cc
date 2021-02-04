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
    TreeNode *trimBST(TreeNode *root, int low, int high)
    {
        return trimBSTRecursive(root, low, high);
    }

    TreeNode *trimBSTRecursive(TreeNode *root, int low, int high)
    {
        if (!root)
            return nullptr;
        
        if (root->val < low)
            return trimBSTRecursive(root->right, low, high);

        if (root->val > high)
            return trimBSTRecursive(root->left, low, high);

        root->left = trimBSTRecursive(root->left, low, high);
        root->right = trimBSTRecursive(root->right, low, high);
        return root;
    }

    TreeNode *trimBSTIter(TreeNode *root, int low, int high)
    {
        if (!root)
            return nullptr;

        TreeNode *l = root, *parent = nullptr;
        while (l)
        {
            if (l->val < low)
            {
                if (!parent)
                {
                    root = l->right;
                    l = l->right;
                }
                else
                {
                    l = l->right;
                    parent->left = l;
                }
            }
            else
            {
                parent = l;
                l = l->left;
            }
        }

        TreeNode *r = root;
        parent = nullptr;

        while (r)
        {
            if (r->val > high)
            {
                if (!parent)
                {
                    root = r->left;
                    r = r->left;
                }
                else
                {
                    r = r->left;
                    parent->right = r;
                }
            }
            else
            {
                parent = r;
                r = r->right;
            }
        }

        return root;
    }
};