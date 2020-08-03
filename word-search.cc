#include <vector>
#include <string>

class Solution
{
private:
    bool search(std::vector<std::vector<char>> &board, std::vector<std::vector<int>> &walked, std::string &word, int i, int j, int now)
    {
        if (now == word.size())
        {
            return true;
        }

        bool res = false;

        if (i > 0 && !walked[i - 1][j] && board[i - 1][j] == word[now])
        {
            walked[i - 1][j] = 1;
            res = search(board, walked, word, i - 1, j, now + 1);
            walked[i - 1][j] = 0;
        }

        if (!res && i < board.size() - 1 && !walked[i + 1][j] && board[i + 1][j] == word[now])
        {
            walked[i + 1][j] = 1;
            res = search(board, walked, word, i + 1, j, now + 1);
            walked[i + 1][j] = 0;
        }

        if (!res && j > 0 && !walked[i][j - 1] && board[i][j - 1] == word[now])
        {
            walked[i][j - 1] = 1;
            res = search(board, walked, word, i, j - 1, now + 1);
            walked[i][j - 1] = 0;
        }

        if (!res && j < board.front().size() - 1 && !walked[i][j + 1] && board[i][j + 1] == word[now])
        {
            walked[i][j + 1] = 1;
            res = search(board, walked, word, i, j + 1, now + 1);
            walked[i][j + 1] = 0;
        } 

        return res;
    }

public:
    bool exist(std::vector<std::vector<char>> &board, std::string &word)
    {
        if (!board.size() || !board.front().size() || !word.size())
            return false;

        std::vector<std::vector<int>> walked(board.size(), std::vector<int>(board.front().size(), 0));

        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board.front().size(); j++)
            {
                if (board[i][j] == word.front())
                {
                    bool res;
                    walked[i][j] = 1;
                    res = search(board, walked, word, i, j, 1);
                    walked[i][j] = 0;

                    if (res)
                        return true;
                }
            }

        return false;
    }
};