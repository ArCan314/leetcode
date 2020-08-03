#include <string>

class Trie
{
private:
    bool has_content = false;
    Trie *childs[26]{};
    void _insert(const std::string &word, const int pos)
    {
        int ind = word[pos - 1] - 'a';
        if (!childs[ind])
            childs[ind] = new Trie();
        if (pos == word.size())
        {
            childs[ind]->has_content = true;
            return;
        }
        else
        {
            childs[ind]->_insert(word, pos + 1);
        }
    }

    bool _search(const std::string &word, const int pos) const
    {
        if (pos == word.size())
        {
            if (has_content)
                return true;
            else
                return false;
        }
        // std::cout << word[pos] << ", " << word[pos] - 'a' << std::endl;
        int ind = word[pos] - 'a';
        if (childs[ind])
        {
            return childs[ind]->_search(word, pos + 1);
        }
        else
        {
            return false;
        }

    }

    bool _startsWith(const std::string &prefix, const int pos) const
    {
        if (pos == prefix.size())
        {
            return true;
        }
        int ind = prefix[pos] - 'a';
        if (childs[ind])
        {
            return childs[ind]->_startsWith(prefix, pos + 1);
        }
        else
        {
            return false;
        }
    }

public:
    /** Initialize your data structure here. */
    
    Trie()
    {
    }

    /** Inserts a word into the trie. */
    void insert(std::string word)
    {
        _insert(word, 1);
    }

    /** Returns if the word is in the trie. */
    bool search(std::string word)
    {
        return _search(word, 0);
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(std::string prefix)
    {
        return _startsWith(prefix, 0);
    }

    ~Trie()
    {
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */