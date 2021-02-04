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

class Solution
{
public:
    static constexpr int kLeft = 0;
    static constexpr int kRight = 1;

    bool findNode(TreeNode *node, TreeNode *target, std::vector<int> &path)
    {
        if (!node)
            return false;
        
        if (node == target)
            return true;
        
        path.push_back(kLeft);
        bool res = findNode(node->left, target, path);
        if (res)
            return true;
        
        path.back() = kRight;
        res = findNode(node->right, target, path);
        if (res)
            return true;
        path.pop_back();
        return false;
    }

    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target)
    {
        std::vector<int> path;
        findNode(original, target, path);

        TreeNode *res = cloned;
        for (const auto dir : path)
        {
            if (dir == kLeft)
                res = res->left;
            else
                res = res->right;
        }

        return res;
    }
};