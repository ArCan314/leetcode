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
#include <vector>

class Solution
{
public:

    bool _isValidSequence(TreeNode *node, int cur, std::vector<int> &arr)
    {
        if (cur == arr.size() - 1)
        {
            if (arr[cur] == node->val && !node->left && !node->right)
                return true;
            else
                return false;
        }

        if (arr[cur] != node->val)
            return false;
        
        bool res = false;
        if (node->left)
            res = _isValidSequence(node->left, cur + 1, arr);
        
        if (!res && node->right)
            res = _isValidSequence(node->right, cur + 1, arr);

        return res;
    }

    bool isValidSequence(TreeNode *root, std::vector<int> &arr)
    {
        if (!root || !arr.size())
            return false;
        bool res = false;
        res = _isValidSequence(root, 0, arr);
        return res;
    }
};