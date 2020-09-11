#include <vector>
#include <string>
#include <array>
#include <unordered_set>

class Trie
{
public:
    Trie() = default;
    Trie(std::vector<std::string> &words)
    {
        for (const auto &word : words)
        {
            Trie *cur = this;
            for (const auto c : word)
            {
                if (cur->hasChild(c))
                    cur = cur->getChild(c);
                else
                {
                    cur->childs[c - 'a'] = new Trie();
                    cur = cur->childs[c - 'a'];
                }
            }
            cur->count++;
        }
    }

    bool hasChild(const char c) { return childs[c - 'a']; }
    int getCount() const noexcept { return count; }
    Trie *getChild(const char c) { return childs[c - 'a']; }

private:
    Trie *childs[26]{nullptr};
    int count{0};
};

class Solution
{
public:
    std::array<std::pair<int, int>, 4> diff
    {
        std::pair<int, int>{-1, 0},
        std::pair<int, int>{1, 0},
        std::pair<int, int>{0, 1},
        std::pair<int, int>{0, -1},
    };

    bool check(const std::vector<std::vector<char>> &board, int row, int col)
    {
        return row >= 0 && row < board.size() && col >= 0 && col < board.front().size(); 
    }

    void findWordDFS(const std::vector<std::vector<char>>    &board, 
                               std::vector<std::vector<int>> &visited, 
                                                        Trie *cur, 
                             std::unordered_set<std::string> &res_set,
                                                 std::string &res_str,
                                                          int row, 
                                                          int col)
    {
        for (int i = 0; i < diff.size(); i++)
        {
            const auto [dx, dy] = diff[i];
            if (check(board, row + dy, col + dx) && !visited[row + dy][col + dx] && cur->hasChild(board[row + dy][col + dx]))
            {
                res_str.push_back(board[row + dy][col + dx]);
                visited[row + dy][col + dx] = 1;
                if (cur->getChild(res_str.back())->getCount())
                    res_set.insert(res_str);
                findWordDFS(board, visited, cur->getChild(res_str.back()), res_set, res_str, row + dy, col + dx);
                visited[row + dy][col + dx] = 0;
                res_str.pop_back();
            }
        }
    }

    std::vector<std::string> findWords(std::vector<std::vector<char>> &board, std::vector<std::string> &words)
    {
        if (!board.size() || !board.front().size())
            return {};
        Trie trie(words);
        std::unordered_set<std::string> word_set;
        std::vector<std::vector<int>> visited(board.size(), std::vector<int>(board.front().size(), 0));
        std::string res_str;
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board.front().size(); j++)
            {
                if (trie.hasChild(board[i][j]))
                {
                    visited[i][j] = 1;
                    res_str.push_back(board[i][j]);

                    if (trie.getChild(board[i][j])->getCount())
                        word_set.insert(res_str);

                    findWordDFS(board, visited, trie.getChild(res_str.back()), word_set, res_str, i, j);
                    visited[i][j] = 0;
                    res_str.pop_back();
                }
            }
                
        return std::vector<std::string>(word_set.begin(), word_set.end());
    }
};