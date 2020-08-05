#include <string>
#include <unordered_map>
#include <deque>
#include <algorithm>

class WordDictionary
{
public:
    /** Initialize your data structure here. */
    WordDictionary()
    {
    }

    /** Adds a word into the data structure. */
    void addWord(std::string word)
    {
        WordDictionary *cur = this;
        for (const char c : word)
            if (auto i = cur->childs.find(c); i != cur->childs.end())
                cur = i->second;
            else
                cur = cur->childs.insert({c, new WordDictionary()}).first->second;
        cur->count++;
    }

    bool _search(const std::string &word, int pos)
    {
        if (pos == word.size())
            return count;
        
        if (char tar = word[pos]; tar == '.')
        {
            for (const auto &child : childs)
                if (child.second->_search(word, pos + 1))
                    return true;
        }
        else
        {
            if (auto i = childs.find(tar); i != childs.end())
                return i->second->_search(word, pos + 1);
        }
        
        return false;
    }

    bool search(std::string word)
    {
        return _search(word, 0);
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool searchBFS(std::string word)
    {
        std::deque<WordDictionary *> cur_nodes;
        cur_nodes.push_back(this);
        for (const auto c : word)
        {
            std::deque<WordDictionary *> temp_nodes;
            if (c != '.')
            {
                std::for_each(cur_nodes.begin(), cur_nodes.end(),
                    [this, c, &temp_nodes](WordDictionary *p)
                    {
                        if (auto i = p->childs.find(c); i != p->childs.end())
                            temp_nodes.push_back(i->second);
                    });
            }
            else
            {
                std::for_each(cur_nodes.begin(), cur_nodes.end(),
                    [this, &temp_nodes](WordDictionary *p)
                    {
                        for (auto child : p->childs)
                            temp_nodes.push_back(child.second);
                    });
            }
            if (temp_nodes.size())
                cur_nodes.swap(temp_nodes);
            else
                return false;
        }

        for (const auto node : cur_nodes)
            if (node->count)
                return true;
        return false;
    }
private:
    int count = 0;
    std::unordered_map<char, WordDictionary *> childs;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */