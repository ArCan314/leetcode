#include <vector>
#include <algorithm>
#include <iostream>

class Solution
{
public:
    std::vector<std::vector<int>> diagonalSort(std::vector<std::vector<int>> &mat)
    {
        int m = mat.size(), n = mat.front().size();
        std::vector<std::vector<int>> mat_diag(m + n - 1, std::vector<int>{});

        int cur = 0;
        for (int i = n - 1; i >= 0; i--, cur++)
            for (int j = 0, k = i; j < m && k < n; j++, k++)
                mat_diag[cur].push_back(mat[j][k]);
        
        for (int i = 1; i < m; i++, cur++)
            for (int j = i, k = 0; j < m && k < n; j++, k++)
                mat_diag[cur].push_back(mat[j][k]);

        for (int i = 0; i < mat_diag.size(); i++)
            std::sort(mat_diag[i].begin(), mat_diag[i].end());
        
        // for (const auto &a : mat_diag)
        // {
        //     for (const auto b : a)
        //         std::cout << b << ", ";
        //     std::cout << endl;
        // }
        
        cur = 0;
        for (int i = n - 1; i >= 0; i--, cur++)
            for (int j = 0, k = i; j < m && k < n; j++, k++)
                mat[j][k] = mat_diag[cur][j];
        for (int i = 1; i < m; i++, cur++)
            for (int j = i, k = 0; j < m && k < n; j++, k++)
                mat[j][k] = mat_diag[cur][k];

        return mat;
    }
};