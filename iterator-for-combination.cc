#include <string>
#include <vector>
#include <algorithm>

class CombinationIterator
{
public:
    CombinationIterator(std::string characters, int combinationLength)
    {
        std::vector<char> chars(characters.begin(), characters.end());
        std::string comb;
        init(chars, comb, -1, combinationLength);
    }

    std::string next()
    {
        return cmbs[now++];
    }

    bool hasNext()
    {
        return now < cmbs.size();
    }
private:
    std::vector<std::string> cmbs;
    int now = 0;

    void init(std::vector<char> &chars, std::string &comb, int pre_pos, int tar_len)
    {
        if (comb.size() == tar_len)
        {
            cmbs.push_back(comb);
            return;
        }

        for (int i = pre_pos + 1; i < chars.size(); i++)
        {
            if (chars.size() - i < tar_len - comb.size())
                break;
            comb.push_back(chars[i]);
            init(chars, comb, i, tar_len);
            comb.pop_back();
        }
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */