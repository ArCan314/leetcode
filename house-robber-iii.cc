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
#include <algorithm>
#include <unordered_map>

class Solution
{
public:
    int _robMemo(TreeNode *node, bool is_rob, std::unordered_map<TreeNode *, int> &fsave, std::unordered_map<TreeNode *, int> &tsave)
    {
        if (!node)
            return 0;

        int lmax, rmax, lrmax, rrmax;
        lmax = rmax = lrmax = rrmax = 0;
        if (auto i = fsave.find(node->left); i != fsave.end())
            lmax = i->second;
        else
        {
            lmax = _robMemo(node->left, false, fsave, tsave);
            fsave[node->left] = lmax;
        }

        if (auto i = fsave.find(node->right); i != fsave.end())
            rmax = i->second;
        else
        {
            rmax = _robMemo(node->right, false, fsave, tsave);
            fsave[node->right] = rmax;
        }

        if (is_rob)
            return lmax + rmax;
        else
        {
            if (auto i = tsave.find(node->left); i != tsave.end())
                lrmax = i->second;
            else
            {
                lrmax = _robMemo(node->left, true, fsave, tsave);
                tsave[node->left] = lrmax;
            }

            if (auto i = tsave.find(node->right); i != tsave.end())
                rrmax = i->second;
            else
            {
                rrmax = _robMemo(node->right, true, fsave, tsave);
                tsave[node->right] = rrmax;
            }

            return std::max(lmax + rmax, lrmax + rrmax + node->val);
        }
        return 0;
    }

    int robMemo(TreeNode *root)
    {
        std::unordered_map<TreeNode *, int> temp_a, temp_b;
        return _robMemo(root, false, temp_a, temp_b);
    }

    int _robWithoutMemo(TreeNode *node, int &l, int &r)
    {
        if (!node)
            return 0;
        int ll, lr, rl, rr;
        ll = lr = rl = rr = 0;
        l = _robWithoutMemo(node->left, ll, lr);
        r = _robWithoutMemo(node->right, rl, rr);
        return std::max(node->val + ll + lr + rl + rr, l + r);
    }

    int robWithoutMemo(TreeNode *node)
    {
        int l, r;
        return _robWithoutMemo(node, l, r);
    }

    int rob(TreeNode *root)
    {
        return robWithoutMemo(root);
    }
};