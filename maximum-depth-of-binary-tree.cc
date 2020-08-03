#define LOCAL
#ifdef LOCAL
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
#endif // LOCAL

#define RECURSION
#ifdef RECURSION

#include <algorithm>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (!root)
            return 0;

        int left_depth, right_depth;
        left_depth = right_depth = 0;

        if (root->left) 
            left_depth = maxDepth(root->left);
            
        if (root->right)
            right_depth = maxDepth(root->right);

        return std::max(left_depth, right_depth) + 1;
    }
};
#endif // RECURSION

#define ITERATION
#ifdef ITERATION

#include <algorithm>
#include <vector>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        std::vector<TreeNode *> node_stack;
        bool is_fin = false;
        if (!root)
            return 0;
        
        node_stack.push_back(root);

        while (!is_fin)
        {
            while (node_stack.size())
            {

            }
        }
    }
};

#endif // ITERATION