struct TreeNode {
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
    unsigned long long res;
    void _sumNumbers(TreeNode *node, unsigned long long sum)
    {
        if (!node->left && !node->right)
        {
            res += 10ull * sum + node->val;
            return;
        }

        if (node->left)
            _sumNumbers(node->left, 10ull * sum + node->val);
        if (node->right)
            _sumNumbers(node->right, 10ull * sum + node->val);
    }

    int sumNumbers(TreeNode *root)
    {
        res = 0;
        _sumNumbers(root, 0);
        return res;
    }
};