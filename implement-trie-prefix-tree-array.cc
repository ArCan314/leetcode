#include <string>
#include <iostream>

class Trie
{
public:
    /** Initialize your data structure here. */
    Trie()
    {
    }

    static constexpr int getPos(char c) noexcept { return c - 'a'; }

    /** Inserts a word into the trie. */
    void insert(std::string word)
    {
        // std::cout << "insert word: " << word << std::endl;
        Trie *cur = this;
        for (const char c : word)
        {
            if (cur->childs[getPos(c)])
                cur = cur->childs[getPos(c)];
            else
            {
                cur->childs[getPos(c)] = new Trie();
                cur = cur->childs[getPos(c)];
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
            if (cur->childs[getPos(c)])
                cur = cur->childs[getPos(c)];
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
            if (cur->childs[getPos(c)])
                cur = cur->childs[getPos(c)];
            else
                return false;
        
        return true;
    }
private:
    int count = 0;
    Trie *childs[26]{nullptr};
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */