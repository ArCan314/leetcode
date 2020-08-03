#include <deque>
#include <unordered_map>
#include <algorithm>

class LRUCache
{
public:
    int size;
    int cur_size;
    std::deque<int> dq;                               // key
    std::unordered_map<int, std::pair<int, int>> has; // key --> <nums, value>
    LRUCache(int capacity) : size(capacity), cur_size(0)
    {
    }

    int get(int key)
    {
        if (auto &[num, val] = has[key]; num <= 0)
        {
            return -1;
        }
        else
        {
            dq.push_back(key);
            num++;
            return val;
        }
    }

    void put(int key, int value)
    {
        if (auto &[num, val] = has[key]; num <= 0)
        {
            if (cur_size == size)
            {
                while (has[dq.front()].first > 1)
                {
                    has[dq.front()].first--;
                    dq.pop_front();
                }
                has[dq.front()].first--;
                dq.pop_front();
                num++;
                val = value;
                dq.push_back(key);
            }
            else
            {
                num++;
                val = value;
                dq.push_back(key);
                cur_size++;
            }
        }
        else
        {
            num++;
            val = value;
            dq.push_back(key);
        }
    }
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */