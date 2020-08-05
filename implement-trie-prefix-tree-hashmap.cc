#include <string>
#include <unordered_map>
#include <iostream>

class Trie
{
public:
    /** Initialize your data structure here. */
    Trie()
    {
    }

    /** Inserts a word into the trie. */
    void insert(std::string word)
    {
        // std::cout << "insert word: " << word << std::endl;
        Trie *cur = this;
        for (const char c : word)
        {
            if (auto i = cur->childs.find(c); i != cur->childs.end())
                cur = i->second;
            else
            {
                cur->childs[c] = new Trie();
                cur = cur->childs[c];
            }
        }
        cur->count++;
    }

    /** Returns if the word is in the trie. */
    bool search(std::string word)
    {
        // std::cout << "search word: " << word << std::endl;
        Trie *cur = this;
        for (const char c : word)
            if (auto i = cur->childs.find(c); i != cur->childs.end())
                cur = i->second;
            else
                return false;
        
        return cur->count;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(std::string prefix)
    {
        // std::cout << "starts with prefix: " << prefix << std::endl;
        Trie *cur = this;
        for (const char c : prefix)
            if (auto i = cur->childs.find(c); i != cur->childs.end())
                cur = i->second;
            else
                return false;
        
        return true;
    }
private:
    int count = 0;
    std::unordered_map<char, Trie *> childs;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */