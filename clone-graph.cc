#include <vector>

class Node
{
public:
    int val;
    std::vector<Node *> neighbors;
    Node();
    Node(int _val);
    Node(int _val, std::vector<Node *> _neighbors);
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
#include <unordered_map>
#include <unordered_set>
#include <deque>

class Solution
{
public:
    Node *cloneGraph(Node *node)
    {
        if (!node)
            return nullptr;

        std::unordered_map<Node *, Node *> visited;
        std::deque<Node *> cur_q;

        cur_q.push_back(node);
        Node *head = new Node(node->val);
        visited[node] = head;

        while (!cur_q.empty())
        {
            Node *cur_node = cur_q.front();
            cur_q.pop_front();

            for (auto neighbor : cur_node->neighbors)
            {
                if (visited.find(neighbor) == visited.end())
                {
                    visited[neighbor] = new Node(neighbor->val);
                    cur_q.push_back(neighbor);
                }

                visited[cur_node]->neighbors.push_back(visited[neighbor]);
            }
        }

        return head;
    }
};