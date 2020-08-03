#include <vector>

class Solution {
public:
    int numTeams(const std::vector<int>& rating) {
        int res = 0;
        bool is_greater = false;
        for (int i = 0; i < rating.size(); i++)
        {
            for (int j = i + 1; j < rating.size(); j++)
            {
                if (rating[j] > rating[i] || rating[j] < rating[i])
                {
                    is_greater = rating[j] > rating[i];
                    for (int k = j + 1; k < rating.size(); k++)
                    {
                        if (is_greater && rating[k] > rating[j])
                        {
                            res++;
                        }
                        else if (!is_greater && rating[k] < rating[j])
                        {
                            res++;
                        }
                    }
                }
            }
        }
        return res;
    }
};