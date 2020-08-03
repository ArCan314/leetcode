#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

class FirstUnique
{
public:
    std::unordered_map<int, int> hash_map;
    std::vector<int> q;
    int ind;

    FirstUnique(std::vector<int> &nums)
        : q(nums), hash_map(), ind(0)
    {
        for (int i = 0; i < q.size(); i++)
            hash_map[q[i]]++;
        for (ind = 0; ind < q.size(); ind++)
            if (hash_map[q[ind]] == 1)
                break;
            
        // for (const auto &[key, val] : hash_map)
        //     std::cout << "key: " << key << ", val: " << val << std::endl; 
    }

    int showFirstUnique()
    {
        // std::cout << "get uniq: " << ind << ", val: " << q[ind] << std::endl; 
        return (ind < q.size()) ? q[ind] : -1;
    }

    void add(int value)
    {
        q.push_back(value);
        hash_map[value]++;
        if (hash_map[q[ind]] > 1)
            for (; ind < q.size(); ind++)
            {
                // std::cout << "val: " << q[ind] << ", map_val: " << hash_map[q[ind]] << std::endl;
                if (hash_map[q[ind]] == 1)
                    break;
            }
        // std::for_each(q.begin(), q.end(), [](auto c){std::cout << c << ", ";});
        // std::cout << std::endl;
        // std::cout << "add val: " << value << ", new ind: " << ind  << ", val: " << q[ind] << std::endl;
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */