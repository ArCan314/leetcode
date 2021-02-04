#include <vector>
#include <unordered_set>
#include <numeric>

class Solution {
public:
    std::vector<int> fairCandySwap(std::vector<int>& A, std::vector<int>& B) 
    {
        std::unordered_set<int> b_nums;
        b_nums.reserve(B.size());

        for (int i = 0; i < B.size(); i++)
            b_nums.insert(B[i]);

        int sum_a = std::accumulate(A.begin(), A.end(), 0);
        int sum_b = std::accumulate(B.begin(), B.end(), 0);
        
        for (int i = 0; i < A.size(); i++)
            if (auto iter = b_nums.find(A[i] + (sum_b - sum_a) / 2); iter != b_nums.end())
                return {A[i], *iter};

        return {};
    }
};

// sum_a - ans[0] + ans[1] == sum_b - ans[1] + ans[0]
// 2 * ans[0] - sum_a + sum_b ==  2 * ans[1]