#include <string>

class WordDictionary
{
public:
    /** Initialize your data structure here. */
    WordDictionary()
    {
    }

    static constexpr int kSize = 'z' - 'a' + 1;
    static constexpr int getPos(const char c) noexcept { return c - 'a'; }

    /** Adds a word into the data structure. */
    void addWord(std::string word)
    {
        WordDictionary *cur = this;
        for (const char c : word)
        {
            if (!cur->childs[getPos(c)])
                cur->childs[getPos(c)] = new WordDictionary();
            cur = cur->childs[getPos(c)];
        }
        cur->count++;
    }

    bool _search(const std::string &word, int pos)
    {
        if (pos == word.size())
            return count;
        
        if (char tar = word[pos]; tar == '.')
        {
            for (int i = 0; i < kSize; i++)
                if (childs[i] && childs[i]->_search(word, pos + 1))
                    return true;
        }
        else
        {
            if (childs[getPos(tar)] && childs[getPos(tar)]->_search(word, pos + 1))
                return true;
        }
        
        return false;
    }

    bool search(std::string word)
    {
        return _search(word, 0);
    }

private:
    int count = 0;
    WordDictionary *childs[kSize]{nullptr};
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */