#include <list>
#include <array>
#include <algorithm>
#include <iostream>

class MyHashMap
{
public:
    using KeyType = int;
    using ValType = int;
    static constexpr std::size_t kSize = 1000;

    /** Initialize your data structure here. */
    MyHashMap()
    {
    }

    /** value will always be non-negative. */
    void put(int key, int value)
    {
        auto &tar_list = set_[key % kSize];
        auto res = std::find_if(tar_list.begin(), tar_list.end(), [key](const auto &kv) { return kv.first == key; });
        if (res == tar_list.end())
            tar_list.emplace_back(key, value); // insert kv pair
        else
            res->second = value; // update value
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key)
    {
        auto &tar_list = set_[key % kSize];
        auto res = std::find_if(tar_list.begin(), tar_list.end(), [key](const auto &kv) { return kv.first == key; });
        if (res == tar_list.end())
            return -1;
        return res->second;
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key)
    {
        auto &tar_list = set_[key % kSize];
        auto res = std::find_if(tar_list.begin(), tar_list.end(), [key](const auto &kv) { return kv.first == key; });
        if (res != tar_list.end())
            tar_list.remove(*res);
    }

private:
    std::array<std::list<std::pair<KeyType, ValType>>, kSize> set_{};
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */