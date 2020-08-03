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
    bool hasPathSum(TreeNode *root, int sum)
    {
        if (root == nullptr)
            return false;

        if (root->left != nullptr || root->right != nullptr) // not leaf
        {
            bool res;
            if (root->left != nullptr)
                res = hasPathSum(root->left, sum - root->val);
            if (res == false && root->right != nullptr)
                res = hasPathSum(root->right, sum - root->val);

            return res;
        }
        else // leaf
        {
            if (sum == root->val)
                return true;
            else
                return false;
        }
    }
};