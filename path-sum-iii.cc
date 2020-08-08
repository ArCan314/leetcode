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
#include <map>

class Solution
{
public:
    int pathSum(TreeNode *root, int target)
    {
        return pathSumRec(root, target);
    }

    int res;

    std::map<int, int> _pathSumMap(TreeNode *node, int target)
    {
        if (!node)
            return {};

        auto lsum_map = _pathSumMap(node->left, target);
        auto rsum_map = _pathSumMap(node->right, target);

        std::map<int, int> ret;
        ret[node->val] = 1;

        for (const auto [val, freq] : lsum_map)
            ret[val + node->val] += freq;
        for (const auto [val, freq] : rsum_map)
            ret[val + node->val] += freq;

        if (ret.count(target))
            res += ret[target];

        return ret;
    }

    int pathSumMap(TreeNode *root, int target)
    {
        res = 0;
        _pathSumMap(root, target);
        return res;
    }

    int _pathSumRec(TreeNode *node, int target)
    {
        if (!node)
            return 0;
        
        int temp = target - node->val;

        return !temp + _pathSumRec(node->left, temp) + _pathSumRec(node->right, temp); 
    }

    int pathSumRec(TreeNode *root, int target)
    {
        if (!root)
            return 0;
        
        return _pathSumRec(root, target) + pathSumRec(root->left, target) + pathSumRec(root->right, target);
    }
};