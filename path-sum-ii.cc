#include <vector>

struct TreeNode {
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
class Solution {
private:
    std::vector<std::vector<int>> res;

    void _pathSum(TreeNode *root, int sum, std::vector<int> &path)
    {
        if (!root)
            return;

        if (!root->left && !root->right) // leaf
        {
            if (sum == root->val)
            {
                path.push_back(sum);
                res.push_back(path);
                path.pop_back();
            }
        }
        else
        {
            path.push_back(root->val);
            _pathSum(root->left, sum - root->val, path);
            _pathSum(root->right, sum - root->val, path);
            path.pop_back();
        }
    }
public:
    std::vector<std::vector<int>> pathSum(TreeNode* root, int sum) 
    {
        std::vector<int> path{};
        res.clear();

        _pathSum(root, sum, path);

        return res;
    }
};