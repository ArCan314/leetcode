
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
#include <algorithm>
#include <deque>

class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        return maxDepthIteration(root);
    }

    int maxDepthRecursion(TreeNode *root)
    {
        if (!root)
            return 0;
        return std::max(maxDepthRecursion(root->left), maxDepthRecursion(root->right)) + 1;
    }

    int maxDepthIteration(TreeNode *root)
    {
        if (!root)
            return 0;

        std::deque<std::pair<TreeNode *, int>> expand;
        expand.push_back({root, 1});
        int res = 1;

        while (!expand.empty())
        {
            const auto [cur, depth] = expand.front();
            expand.pop_front();
            
            if (cur->left)
                expand.emplace_back(cur->left, depth + 1);
            if (cur->right)
                expand.emplace_back(cur->right, depth + 1);
            
            res = std::max(depth, res);
        }
        return res;
    }
};
