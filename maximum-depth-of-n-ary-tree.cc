#include <vector>

class Node
{
public:
    int val;
    std::vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, std::vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
#include <deque>

class Solution
{
public:
    int maxDepth(Node *root)
    {
        return maxDepthBFS(root);
    }

    int maxDepthDFS(Node *root)
    {
        if (!root)
            return 0;

        int res = 0;
        for (auto child : root->children)
            res = std::max(maxDepthDFS(child), res);

        return res + 1;
    }

    int maxDepthBFS(Node *root)
    {
        if (!root)
            return 0;

        std::deque<Node *> expand;
        int res = 0;
        expand.push_back(root);

        while (!expand.empty())
        {
            res++;
            int size = expand.size();
            for (int i = 0; i < size; i++)
            {
                const auto cur = expand.front();
                expand.pop_front();

                for (const auto child : cur->children)
                    expand.push_back(child);
            }
        }
        return res;
    }
};