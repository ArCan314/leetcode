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
#include <queue>
#include <tuple>
#include <map>
#include <algorithm>

class Solution
{
public:
    using QValType = std::tuple<int, int, int>;
    using QType = std::priority_queue<QValType, std::vector<QValType>, std::greater<QValType>>;

    std::vector<std::vector<int>> verticalTraversal(TreeNode *root)
    {
        return verticalTraversalMap(root);
    }

    using MapType = std::map<int, std::map<int, std::vector<int>>>;
    void _verticalTraversalMap(TreeNode *node, int x, int y, MapType &map)
    {
        if (!node)
            return;
        map[x][y].push_back(node->val);
        _verticalTraversalMap(node->left, x - 1, y + 1, map);
        _verticalTraversalMap(node->right, x + 1, y + 1, map);
    }

    std::vector<std::vector<int>> verticalTraversalMap(TreeNode *root)
    {
        MapType map;
        std::vector<std::vector<int>> res;
        _verticalTraversalMap(root, 0, 0, map);
        for (auto &[x, sub_map] : map)
        {
            res.push_back({});
            for (auto &[y, vec] : sub_map)
            {
                std::sort(vec.begin(), vec.end());
                std::copy(vec.begin(), vec.end(), std::back_insert_iterator(res.back()));
            }
        }
        return res;
    }

    void _verticalTraversalPQ(TreeNode *node, int x, int y, QType &q)
    {
        if (!node)
            return;

        q.push({x, y, node->val});
        _verticalTraversalPQ(node->left, x - 1, y + 1, q);
        _verticalTraversalPQ(node->right, x + 1, y + 1, q);
    }

    std::vector<std::vector<int>> verticalTraversalPQ(TreeNode *root)
    {
        QType q;
        std::vector<std::vector<int>> res;
        std::vector<int> temp_vec;
        _verticalTraversalPQ(root, 0, 0, q);
        int temp = std::get<0>(q.top());
        while (!q.empty())
        {
            if (std::get<0>(q.top()) == temp)
                temp_vec.push_back(std::get<2>(q.top()));
            else
            {
                res.push_back(temp_vec);
                temp_vec.clear();
                temp = std::get<0>(q.top());
                temp_vec.push_back(std::get<2>(q.top()));
            }
            q.pop();
        }
        res.push_back(temp_vec);
        return res;
    }
};