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
#include <utility>

class Solution
{
public:

    bool find(TreeNode *node, int val, int parent_val, int depth, std::pair<int, int> &p)
    {
        if (!node)
            return false;
        
        if (node->val == val)
        {
            p = {depth, parent_val};
            return true;
        }

        bool res = find(node->left, val, node->val, depth + 1, p);
        if (!res)
            res = find(node->right, val, node->val, depth + 1, p);
        return res;
    }


    bool isCousins(TreeNode *root, int x, int y)
    {
        std::pair<int, int> px, py;
        bool res = find(root, x, 0, 0, px);
        if (res)
            res = find(root, y, 0, 0, py);
        
        return res ? (px.first == py.first && py.second != px.second) : false;
    }
};