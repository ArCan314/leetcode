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

class Solution
{
public:
    void _sortedArrayToBST(TreeNode *node, const std::vector<int> &nums, int l, int r)
    {
        if (l >= r)
            return;

        int mid = (l + r) / 2;
        node = new TreeNode(nums[mid]);
        _sortedArrayToBST(node->left, nums, l, mid);
        _sortedArrayToBST(node->right, nums, mid + 1, r);
    }

    TreeNode *sortedArrayToBST(const std::vector<int> &nums)
    {
        if (!nums.size())
            return nullptr;

        TreeNode *root = nullptr;
        _sortedArrayToBST(root, nums, 0, nums.size());
        return root;
    }
};