#include <vector>
#include <string>

class Solution
{
public:
    std::vector<std::string> fizzBuzz(int n)
    {
        std::vector<std::string> res(n, std::string());
        for (int i = 2; i < n; i+= 3)
        {
            res[i] = "Fizz";
        }
        for (int i = 4; i < n; i+= 5)
        {
            res[i].append("Buzz");
        }
        for (int i = 0; i < n; i++)
        {
            if (!res[i].size())
                res[i] = std::to_string(i + 1);
        }
        return res;
    }
};