#include <vector>
#include <random>
class Solution {
public:
    std::vector<int> arr_;
    std::random_device dev_;
    std::mt19937 rng_;

    Solution(std::vector<int>& nums) : arr_(nums), dev_(), rng_(dev_()) 
    {
    }
    
    /** Resets the array to its original configuration and return it. */
    std::vector<int> reset() 
    {
        return arr_;
    }

    /** Returns a random shuffling of the array. */
    std::vector<int> shuffle() 
    {
        std::vector<int> res(arr_.begin(), arr_.end());
        for (int i = res.size() - 1; i > 0; i--)
        {
            std::uniform_int_distribution<int> dist(0, i - 1);
            std::swap(res[dist(rng_)], res[i]); 
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */