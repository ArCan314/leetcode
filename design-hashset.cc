#include <array>
#include <list>
#include <algorithm>

class MyHashSet
{
public:
    using ElemType = int;
    static constexpr std::size_t kSize = 1000UL; 
    /** Initialize your data structure here. */
    MyHashSet()
    {
    }

    void add(int key)
    {
        set_[key % kSize].push_back(key);
    }

    void remove(int key)
    {
        set_[key % kSize].remove_if([key](ElemType &elem) { return elem == key;} );
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key)
    {
        auto &tar_list = set_[key % kSize];
        return std::find(tar_list.begin(), tar_list.end(), key) != tar_list.end();
    }
private:
    std::array<std::list<ElemType>, kSize> set_{};
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */