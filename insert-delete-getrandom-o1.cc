#include <unordered_map>
#include <vector>
#include <random>

class RandomizedSet
{
public:
    /** Initialize your data structure here. */
    RandomizedSet() : rng(std::random_device()())
    {
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val)
    {
        bool has_val = map.count(val);
        if (!has_val)
        {
            map[val] = vec.size();
            vec.push_back(val);
        }
        return !has_val;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val)
    {
        bool has_val = map.count(val);
        if (has_val)
        {
            std::swap(map[val], map[vec.back()]);
            std::swap(vec[map[vec.back()]], vec.back());
            vec.pop_back();
            map.erase(val);
        }
        return has_val;
    }

    /** Get a random element from the set. */
    int getRandom()
    {
        std::uniform_int_distribution<int> dist(0, vec.size() - 1);
        return vec[dist(rng)];
    }
private:
    std::unordered_map<int, int> map; // <val, pos_in_vec>
    std::vector<int> vec;
    std::mt19937 rng;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */