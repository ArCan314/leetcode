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
#include <iostream>
#include <algorithm>
#include <unordered_map>

class Solution
{
public:
    std::vector<int> *pre, *in;
    std::unordered_map<int, int> elem_ind;

    void buildTreeImpl(TreeNode *node, int in_left, int in_right, int in_parent, int &pre_pos)
    {
        // std::cout << in_left << ", " << in_right << ", " << in_parent << ", " << pre_pos << std::endl;

        if (pre_pos >= pre->size())
            return;

        int l_pos = elem_ind[(*pre)[pre_pos]];
        if (l_pos < in_parent && l_pos <= in_right && l_pos >= in_left)
        {
            node->left = new TreeNode(pre->at(pre_pos++));
            buildTreeImpl(node->left, in_left, in_parent - 1, l_pos, pre_pos);
        }

        if (pre_pos >= pre->size())
            return;

        int r_pos = elem_ind[(*pre)[pre_pos]];
        if (r_pos >= in_left && r_pos <= in_right && r_pos > in_parent)
        {
            node->right = new TreeNode(pre->at(pre_pos++));
            buildTreeImpl(node->right, in_parent + 1, in_right, r_pos, pre_pos);
        }
    }

    void buildTreeImpl2(TreeNode *node, int in_left, int in_right, int in_parent, int &pre_pos)
    {
        // std::cout << in_left << ", " << in_right << ", " << in_parent << ", " << pre_pos << std::endl;

        if (pre_pos >= pre->size())
            return;

        for (int i = in_left; i < in_parent && i <= in_right; i++)
        {
            if (pre_pos < pre->size() && in->at(i) == pre->at(pre_pos))
            {
                node->left = new TreeNode(pre->at(pre_pos++));
                buildTreeImpl2(node->left, in_left, in_parent - 1, i, pre_pos);
                break;
            }
        }

        for (int i = std::max(in_parent, in_left); i <= in_right; i++)
        {
            if (pre_pos < pre->size() && in->at(i) == pre->at(pre_pos))
            {
                node->right = new TreeNode(pre->at(pre_pos++));
                buildTreeImpl2(node->right, in_parent + 1, in_right, i, pre_pos);
                break;
            }
        }
    }

    TreeNode *buildTree(std::vector<int> &preorder, std::vector<int> &inorder)
    {
        pre = &preorder;
        in = &inorder;
        elem_ind.clear();

        if (inorder.empty())
            return nullptr;

        for (int i = 0; i < inorder.size(); i++)
            elem_ind[inorder[i]] = i;

        int pre_pos = 1;
        int in_root = elem_ind[preorder[0]];
        TreeNode *root = new TreeNode(preorder[0]);

        buildTreeImpl2(root, 0, inorder.size() - 1, in_root, pre_pos);
        return root;
    }
};