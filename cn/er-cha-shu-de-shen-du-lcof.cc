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
#include <deque>
#include <algorithm>

class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        return maxDepthBfs(root);
    }

    int maxDepthDfs(TreeNode *node)
    {
        if (!node)
            return 0;

        return std::max(maxDepthDfs(node->left), maxDepthDfs(node->right)) + 1;
    }

    int maxDepthBfs(TreeNode *node)
    {
        if (!node)
            return 0;
        
        std::deque<TreeNode *> expand;
        int level = 0;

        expand.push_back(node);

        while (!expand.empty())
        {
            int size = expand.size();
            level++;
            for (int i = 0; i < size; i++)
            {
                TreeNode *cur = expand.front();
                expand.pop_front();

                if (cur->left)
                    expand.push_back(cur->left);
                if (cur->right)
                    expand.push_back(cur->right);
            }
        }
        return level;
    }
};