#include <string>

class Solution
{
public:
    std::string getHint(std::string &secret, std::string &guess)
    {
        int bulls{}, cows{};
        int char_set[10]{0};
        for (const auto c : secret)
            char_set[c - '0']++;

        for (int i = 0; i < secret.size(); i++)
        {
            if (secret[i] == guess[i])
            {
                char_set[guess[i] - '0']--;
                bulls++;
            }
        }

        for (int i = 0; i < secret.size(); i++)
        {
            if (secret[i] != guess[i] && char_set[guess[i] - '0'])
            {
                char_set[guess[i] - '0']--;
                cows++;
            }
        }

        return std::to_string(bulls)
            .append("A")
            .append(std::to_string(cows))
            .append("B");
    }
};