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
#include <deque>

class Solution
{
public:
    int minDepth(TreeNode *root)
    {
        return minDepthDFS(root);
    }

    int minDepthDFS(TreeNode *root)
    {
        if (!root)
            return 0;

        if (!root->left && !root->right)
            return 1;
        
        int min_depth{0x7fffffff};

        if (root->left)
            min_depth = minDepthDFS(root->left);
        
        if (root->right)
            min_depth = std::min(min_depth, minDepthDFS(root->right));
        
        return min_depth + 1;
    }

    int minDepthBFS(TreeNode *root)
    {
        if (!root)
            return 0;

        std::deque<std::pair<TreeNode *, int>> expand;
        expand.emplace_back(root, 1);
        int res = 1;

        while (!expand.empty())
        {
            const auto [cur, depth] = expand.front();
            expand.pop_front();

            if (!cur->left && !cur->right)
            {
                res = depth;
                break;
            }

            if (cur->left)
                expand.emplace_back(cur->left, depth + 1);
            if (cur->right)
                expand.emplace_back(cur->right, depth + 1);
        }

        return res;
    }
};