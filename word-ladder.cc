#include <string>
#include <vector>
#include <deque>
#include <set>
#include <unordered_set>

class Solution
{
public:
    int ladderLength(const std::string &beginWord, const std::string &endWord, const std::vector<std::string> &wordList)
    {
        std::vector<std::unordered_set<char>> transform_characters(beginWord.size(), std::unordered_set<char>{});
        std::unordered_set<std::string> visited;
        std::unordered_set<std::string> word_in_wordlist(wordList.begin(), wordList.end());
        
        if (!word_in_wordlist.count(endWord))
            return 0;

        std::deque<std::string> expand;

        expand.push_back(beginWord);
        visited.insert(beginWord);
        for (int i = 0; i < beginWord.size(); i++)
            for (int j = 0; j < wordList.size(); j++)
                transform_characters[i].insert(wordList[j][i]);
        int res = 0;
        bool has_find = false;

        while (!expand.empty() && !has_find)
        {
            res++;
            int expand_size = expand.size();
            // cout << "level " << res << endl;
            for (int i = 0; i < expand_size; i++)
            {
                std::string word = std::move(expand.front());
                expand.pop_front();
                // cout << "\tword: " << word << endl;
                if (word == endWord)
                {
                    has_find = true;
                    break;
                }

                for (int i = 0; i < word.size(); i++)
                {
                    char save = word[i];
                    for (const auto transform_char : transform_characters[i])
                    {
                        word[i] = transform_char;
                        if (!visited.count(word) && word_in_wordlist.count(word))
                        {
                            visited.insert(word);
                            expand.push_back(word);
                        }
                    }
                    word[i] = save;
                }
            }
        }
        
        return has_find ? res : 0;
    }
};