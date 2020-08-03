#include <vector>

class Solution
{
public:
    int kthSmallest(std::vector<std::vector<int>> &matrix, int k)
    {
        std::vector<int> pos(matrix.size(), 0);
        int res = 0;

        for (int i = 0; i < k; i++)
        {
            int min_ind = -1;
            for (int j = 0; j < pos.size(); j++)
            {
                if (min_ind == -1 && pos[j] < matrix.front().size())
                    min_ind = j;
                else if (min_ind >= 0 && matrix[j][pos[j]] < matrix[min_ind][pos[min_ind]])
                    min_ind = j;
                // std::cout << "min_ind: " << min_ind << ", j:" << j << std::endl;
            }
            // std::cout << i << ", " << min_ind << std::endl;
            res = matrix[min_ind][pos[min_ind]];
            pos[min_ind]++;
        }

        return res;
    }
};