#include <vector>

class Solution
{
public:
    int countLiveNeighbors(std::vector<std::vector<int>> &board, int r, int c)
    {
        int neighbor_num = 0;
        int lb = std::max(0, c - 1);
        int rb = std::min(static_cast<int>(board.front().size() - 1), c + 1);
        int ub = std::max(0, r - 1);
        int bb = std::min(static_cast<int>(board.size() - 1), r + 1);

        for (int i = ub; i <= bb; i++)
            for (int j = lb; j <= rb; j++)
                if (!(i == r && j == c) && board[i][j])
                    neighbor_num++;
        
        return neighbor_num;
    }

    void gameOfLife(std::vector<std::vector<int>> &board)
    {
        std::vector<std::vector<int>> temp(board.size(), std::vector<int>(board.front().size(), 0));
        
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board.front().size(); j++)
            {
                int neighbor_num = countLiveNeighbors(board, i, j);
                // std::cout << "i: " << i << ", j: " << j << ", neighbor_num: " << neighbor_num << std::endl;
                if (board[i][j])
                {
                    if (neighbor_num < 2)
                        temp[i][j] = 0;
                    else if (neighbor_num > 3)
                        temp[i][j] = 0;
                    else
                        temp[i][j] = 1;
                }
                else
                {
                    if (neighbor_num == 3)
                        temp[i][j] = 1;
                }
            }
        }

        board.swap(temp);
    }
};