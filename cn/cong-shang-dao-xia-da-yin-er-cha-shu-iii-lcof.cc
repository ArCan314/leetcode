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
    std::vector<std::vector<int>> levelOrder(TreeNode *root)
    {
        if (!root)
            return {};

        std::deque<TreeNode *> expand;
        std::vector<std::vector<int>> res;

        expand.push_back(root);
        int level = 0;

        while (!expand.empty())
        {
            int size = expand.size();
            res.emplace_back();

            int start = (level % 2) ? 0 : size - 1;
            int end = (level % 2) ? size : -1;
            int diff = (level % 2) ? 1 : -1; 
            for (int i = start; i != end; i += diff)
                res[level].push_back(expand[i]->val);

            for (int i = 0; i < size; i++)
            {
                if (expand[i]->right)
                    expand.push_back(expand[i]->right);
                if (expand[i]->left)
                    expand.push_back(expand[i]->left);
            }

            for (int i = 0; i < size; i++)
                expand.pop_front();
            
            level++;
        }
        return res;
    }
};