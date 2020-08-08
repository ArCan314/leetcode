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

class Solution
{
public:
    TreeNode *_buildTree(std::vector<int> &preorder, int &cur, std::vector<int> &inorder, int in_cur, int lo, int hi)
    {
        TreeNode *node = new TreeNode(preorder[cur]);


        while (++cur < preorder.size())
        {
            bool is_find = false;
            for (int i = lo; i < hi; i++)
                if (preorder[cur] == inorder[i])
                {
                    if (i < in_cur)
                        node->left = _buildTree(preorder, cur, inorder, i, lo, i);
                    else // i > in_cur
                        node->right = _buildTree(preorder, cur, inorder, i, i + 1, hi);
                    is_find = true;
                }
            
            if (!is_find)
                break;
        }
        return node;
    }

    TreeNode *buildTree(std::vector<int> &preorder, std::vector<int> &inorder)
    {
        if (!preorder.size() || !inorder.size())
            return nullptr;
        int cur = 0, root_pos = 0;
        for (int i = 0; i < inorder.size(); i++)
            if (inorder[i] == preorder[0])
            {
                root_pos = i;
                break;
            }
        return _buildTree(preorder, cur, inorder, root_pos, 0, inorder.size());
    }
};