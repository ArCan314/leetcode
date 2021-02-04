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
#include <iostream>

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        return lowestCommonAncestorRecursive(root, p, q);
    }

    bool DFSFind(TreeNode *node, TreeNode *target, std::stack<TreeNode *> &stack_info)
    {
        if (!node)
            return false;

        if (target == node)
            return true;

        stack_info.push(node->left);
        bool res = DFSFind(node->left, target, stack_info);
        if (!res)
        {
            stack_info.pop();

            stack_info.push(node->right);
            res = DFSFind(node->right, target, stack_info);
            if (!res)
                stack_info.pop();
        }

        return res;
    }

    TreeNode *lowestCommonAncestorStack(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        std::stack<TreeNode *> sa, sb;
        sa.push(root), sb.push(root);

        DFSFind(root, p, sa);
        DFSFind(root, q, sb);

        while (sa.size() > sb.size())
            sa.pop();

        while (sb.size() > sa.size())
            sb.pop();

        while (sa.top() != sb.top())
        {
            sa.pop();
            sb.pop();
        }

        return sa.top();
    }

    TreeNode *lowestCommonAncestorRecursive(TreeNode *node, TreeNode *p, TreeNode *q)
    {
        if (!node)
            return node;
        // std::cout << "enter : " << node->val << std::endl;
        TreeNode *mid = (p == node || q == node) ? node : nullptr;
        TreeNode *left = lowestCommonAncestorRecursive(node->left, p, q);
        TreeNode *right = lowestCommonAncestorRecursive(node->right, p, q);

        // std::cout << "val: " << node->val << ", mid: " << mid << ", left: " << left << ", right: " << right << std::endl; 

        // std::cout << "exit : " << node->val << std::endl;

        if ((mid && left) || (mid && right) || (left && right) || mid)
            return node;

        return left ? left : right;
    }
};