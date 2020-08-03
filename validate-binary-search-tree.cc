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

#include <stack>

class Solution
{
public:
    bool isValidBST(TreeNode *root)
    {
        std::stack<TreeNode *> node_stack;

        long long pre_num = 0x8000000000000000;

        while (!node_stack.empty() || root)
        {
            while (root)
            {
                node_stack.push(root);
                root = root->left;
            }

            root = node_stack.top();
            node_stack.pop();
            

            if (root->val <= pre_num)
            {
                return false;
            }
            
            pre_num = root->val;
            root = root->right;
        }

        return true;
    }
};