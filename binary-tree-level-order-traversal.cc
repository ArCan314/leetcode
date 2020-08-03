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
#include <vector>

class Solution
{
public:
    std::vector<std::vector<int>> levelOrder(TreeNode *root)
    {
        std::vector<std::vector<int>> res;
        
        std::deque<TreeNode *> cur_level, next_level;

        if (!root)
            return res;

        next_level.push_back(root);

        while (next_level.size())
        {
            std::vector<int> temp;
            cur_level.clear();
            cur_level.swap(next_level);
            
            for (const auto &node : cur_level)
                temp.push_back(node->val);
            res.push_back(temp);

            while (cur_level.size())
            {
                TreeNode *top_node = cur_level.front();
                if (top_node->left)
                    next_level.push_back(top_node->left);
                if (top_node->right)
                    next_level.push_back(top_node->right);

                cur_level.pop_front();
            }
        }

        return res;
    }
};