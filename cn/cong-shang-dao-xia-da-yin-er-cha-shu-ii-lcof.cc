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
#include <deque>

class Solution
{
public:
    std::vector<std::vector<int>> res;

    void levelOrderDfs(TreeNode *node, int depth)
    {
        if (!node)
            return;
        
        if (depth == res.size())
            res.emplace_back();
        
        res[depth].push_back(node->val);
        levelOrderDfs(node->left, depth + 1);
        levelOrderDfs(node->right, depth + 1);
    }

    void levelOrderBfs(TreeNode *node)
    {
        if (!node)
            return;

        std::deque<TreeNode *> expand;
        expand.push_back(node);
        int level = 0;

        while (!expand.empty())
        {
            int q_size = expand.size();
            res.emplace_back();

            for (int i = 0; i < q_size; i++)
            {
                TreeNode *cur = expand.front();
                expand.pop_front();

                res[level].push_back(cur->val);

                if (cur->left)
                    expand.push_back(cur->left);
                if (cur->right)
                    expand.push_back(cur->right);
            }
            level++;
        }
    }

    std::vector<std::vector<int>> levelOrder(TreeNode *root)
    {
        res.clear();
        levelOrderBfs(root);
        return res;
    }
};