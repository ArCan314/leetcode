#include <vector>
#include <random>
#include <cmath>

class Solution
{
public:
    static int getRectArea(const std::vector<int> &rect)
    {
        return (1 + std::abs(rect[3] - rect[1])) * (1 + std::abs(rect[2] - rect[0]));
    }

    Solution(std::vector<std::vector<int>> rects) : rng_(std::random_device().operator()()), rects_(std::move(rects))
    {
        for (const auto &rect : rects_)
        {
            if (area_bounds_.size())
                area_bounds_.push_back(area_bounds_.back() + getRectArea(rect));
            else
                area_bounds_.push_back(getRectArea(rect));
        }
        area_sum_ = area_bounds_.back();
    }

    std::vector<int> SamplePointsInRect(std::vector<int> &rect)
    {
        std::uniform_int_distribution x_dist(std::min(rect[0], rect[2]), std::max(rect[0], rect[2]));
        std::uniform_int_distribution y_dist(std::min(rect[1], rect[3]), std::max(rect[1], rect[3]));
        std::vector<int> res(2, 0);
        res[0] = x_dist(rng_), res[1] = y_dist(rng_);
        return res;
    }

    int SampleRect()
    {
        std::uniform_int_distribution area_dist(0, area_sum_);
        auto lower = std::lower_bound(area_bounds_.begin(), area_bounds_.end(), area_dist(rng_));
        return std::distance(area_bounds_.begin(), lower);
        // for (int i = 0; i < area_bounds_.size(); i++)
        //     if (sample_area <= area_bounds_[i])
        //         return i;
        // return 0;
    }

    std::vector<int> pick()
    {
        return SamplePointsInRect(rects_[SampleRect()]);
    }

    std::mt19937 rng_;
    int area_sum_{};
    std::vector<int> area_bounds_;
    std::vector<std::vector<int>> rects_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */