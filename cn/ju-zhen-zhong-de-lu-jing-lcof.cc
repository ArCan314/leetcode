#include <vector>
#include <string>
#include <deque>
#include <unordered_set>

class Solution
{
public:
    int hash(int i, int j, int n)
    {
        return i * n + j;
    }

    bool find(std::vector<std::vector<char>> &board, int i, int j, int pos, std::string &word, std::vector<std::vector<int>> &visit)
    {
        if (pos == word.size() - 1 && board[i][j] == word[pos])
            return true;
        if (board[i][j] != word[pos])
            return false;

        int m = board.size();
        int n = board[0].size();

        bool res = false;
        if (i > 0 && !visit[i - 1][j])
        {
            visit[i - 1][j] = 1;
            res = find(board, i - 1, j, pos + 1, word, visit);
            visit[i - 1][j] = 0;
        }

        if (!res && i < m - 1 && !visit[i + 1][j])
        {
            visit[i + 1][j] = 1;
            res = find(board, i + 1, j, pos + 1, word, visit);
            visit[i + 1][j] = 0;
        }

        if (!res && j > 0 && !visit[i][j - 1])
        {
            visit[i][j - 1] = 1;
            res = find(board, i, j - 1, pos + 1, word, visit);
            visit[i][j - 1] = 0;
        }

        if (!res && j < n - 1 && !visit[i][j + 1])
        {
            visit[i][j + 1] = 1;
            res = find(board, i, j + 1, pos + 1, word, visit);
            visit[i][j + 1] = 0;
        }

        return res;
    }

    bool exist(std::vector<std::vector<char>> &board, std::string &word)
    {
        int m = board.size();
        int n = board[0].size();

        bool res = false;
        std::vector<std::vector<int>> visit(m, std::vector<int>(n, 0));

        for (int i = 0; i < m && !res; i++)
            for (int j = 0; j < n && !res; j++)
            {
                if (board[i][j] == word[0])
                {
                    visit[i][j] = 1;
                    res = find(board, i, j, 0, word, visit);
                    visit[i][j] = 0;
                }
            }
        return res;
    }
};