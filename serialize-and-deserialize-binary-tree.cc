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
#include <string>
#include <deque>
#include <numeric>
#include <vector>

class Codec
{
public:
    // Encodes a tree to a single string.
    std::string serialize(TreeNode *root)
    {
        if (!root)
            return "";
        
        std::string res;
        std::deque<TreeNode *> q;
        q.push_back(root);

        while (q.size())
        {
            std::deque<TreeNode *> temp_q;
            for (int i = 0; i < q.size(); i++)
            {
                if (auto &node = q[i]; node)
                {
                    res.append(std::to_string(node->val).append(" "));
                    temp_q.push_back(node->left);
                    temp_q.push_back(node->right);
                }
                else
                {
                    res.append("null ");
                }
            }
            q.swap(temp_q);
        }

        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(const std::string &data)
    {
        if (!data.size())
            return nullptr;
        
        std::vector<std::string> tokens;
        std::string token;
        for (int i = 0; i < data.size(); i++)
        {
            if (data[i] == ' ')
            {
                tokens.push_back(token);
                token.clear();
            }
            else
            {
                token.push_back(data[i]);
            }
        }
        
        TreeNode *root = new TreeNode(std::stoi(tokens.front()));
        std::deque<TreeNode *> q;
        int pos = 1;
        q.push_back(root);
        while (q.size())
        {
            TreeNode *cur = q.front();
            q.pop_front();

            if (tokens[pos] != "null")
            {
                cur->left = new TreeNode(std::stoi(tokens[pos]));
                q.push_back(cur->left);
            }
            pos++;

            if (tokens[pos] != "null")
            {
                cur->right = new TreeNode(std::stoi(tokens[pos]));
                q.push_back(cur->right);
            }
            pos++;
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));