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
    using Path = std::vector<int>;
    using Paths = std::vector<Path>;

    Paths pathSum(TreeNode *root, int sum)
    {
        return pathSumDfs(root, sum);
    }

    void pathSumDfsImpl(TreeNode *node, int sum, Path &path, Paths &res)
    {
        if (!node->left && !node->right && !sum)
            res.emplace_back(path);

        if (node->left)
        {
            path.push_back(node->left->val);
            pathSumDfsImpl(node->left, sum - path.back(), path, res);
            path.pop_back();
        }

        if (node->right)
        {
            path.push_back(node->right->val);
            pathSumDfsImpl(node->right, sum - path.back(), path, res);
            path.pop_back();
        }
    }

    Paths pathSumDfs(TreeNode *root, int sum)
    {
        if (!root)
            return {};

        Paths res;
        Path temp;
        temp.push_back(root->val);
        pathSumDfsImpl(root, sum - temp.back(), temp, res);
        return res;
    }
};