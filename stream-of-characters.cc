#include <vector>
#include <string>

class Trie
{
public:
    Trie() = default;
    Trie(const std::vector<std::string> &words)
    {
        for (const auto &word : words)
        {
            Trie *cur = this;
            for (int i = word.size() - 1; i >= 0; i--)
            {
                char c = word[i];
                if (cur->hasChild(c))
                    cur = cur->childs[c - 'a'];
                else
                {
                    cur->childs[c - 'a'] = new Trie();
                    cur = cur->childs[c - 'a'];
                }
            }
            cur->count++;
        }
    }

    bool hasChild(const char c) const { return childs[c - 'a']; }
    Trie *getChild(const char c) { return childs[c - 'a']; }
    bool hasCount() { return count; }

private:
    Trie *childs[26]{nullptr};
    int count{0};
};

class StreamChecker
{
public:
    StreamChecker(std::vector<std::string> &words) : trie(new Trie(words))
    {
    }

    bool query(char letter)
    {
        str.push_back(letter);
        bool res = false;
        Trie *cur = trie;
        for (int i = str.size() - 1; i >= 0; i--)
        {
            if (cur->hasChild(str[i]))
            {
                cur = cur->getChild(str[i]);
                if (cur->hasCount())
                    return true;
            }
            else
                return false;
        }

        return false;
    }

    Trie *trie{nullptr};
    std::string str;
};
/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */