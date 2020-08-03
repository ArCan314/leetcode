#include <unordered_map>
#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) 
    {
        std::unordered_map<int,std::vector<int>> num_map;
        std::vector<int> res;

        for (int i = 0; i < nums.size(); i++)
        {
            num_map[nums[i]].push_back(i);
        }

        for (const auto &num_pair : num_map)
        {
            int diff = target - num_pair.first;
            if (diff == num_pair.first)
            {
                if (num_pair.second.size() > 1)
                {
                    res = num_pair.second;
                    break;
                }
            }
            else
            {
                if (num_map.count(diff))
                {
                    res = {num_pair.second.front(), num_map[diff].front()};
                    break;
                }
            }
        }

        return res;
    }
};