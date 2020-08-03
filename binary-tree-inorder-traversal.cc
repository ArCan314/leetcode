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
#include <stack>

class Solution
{
private:
    void _inorderTraversalRec(TreeNode *root)
    {
        std::stack<TreeNode *> node_stack;

        while (!node_stack.empty() || root)
        {
            while (root)
            {
                node_stack.push(root);
                root = root->left;
            }

            root = node_stack.top();
            node_stack.pop();

            res.push_back(root->val);
            root = root->right;
        }
    }

    void _inorderTraversalIter(TreeNode *root)
    {
        if (!root)
            return;
        
        _inorderTraversalRec(root->left);
        res.push_back(root->val);
        _inorderTraversalRec(root->right);
    }

    std::vector<int> res;

public:
    std::vector<int> inorderTraversal(TreeNode *root)
    {
        res.clear();
        _inorderTraversalIter(root);
        return res;
    }
};