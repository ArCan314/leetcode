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
#include <algorithm>

class Solution
{
public:
    std::vector<double> averageOfLevels(TreeNode *root)
    {
        return averageOfLevelsBFS(root);
    }

    void _averageOfLevels(TreeNode *node, std::vector<std::pair<long long, int>> &stat, int depth)
    {
        if (!node)
            return;

        if (stat.size() == depth)
            stat.emplace_back();

        _averageOfLevels(node->left, stat, depth + 1);
        _averageOfLevels(node->right, stat, depth + 1);

        stat[depth].first += node->val;
        stat[depth].second++;
    }

    std::vector<double> averageOfLevelsDFS(TreeNode *root)
    {
        std::vector<std::pair<long long, int>> stat;
        _averageOfLevels(root, stat, 0);
        std::vector<double> avg;
        for (int i = 0; i < stat.size(); i++)
            avg.push_back(static_cast<double>(stat[i].first) / static_cast<double>(stat[i].second));
        return avg;
    }

    std::vector<double> averageOfLevelsBFS(TreeNode *root)
    {   
        if (!root)
            return {};

        std::vector<TreeNode *> cur(1, root);
        std::vector<double> res;

        while (!cur.empty())
        {
            std::vector<TreeNode *> expand;
            int count = cur.size();
            long long sum = 0;
            
            for (const TreeNode *node : cur)
            {
                sum += node->val;
                if (node->left)
                    expand.push_back(node->left);
                if (node->right)
                    expand.push_back(node->right);            
            }

            res.push_back(static_cast<double>(sum) / static_cast<double>(count));
            cur.swap(expand);
        }
        return res;
    }
};