#include <vector>
#include <string>

class Solution
{
public:
    int evalRPN(std::vector<std::string> &tokens)
    {
        std::vector<int> opnums;
        for (int i = 0; i < tokens.size(); i++)
        {
            int opnum1;
            if (tokens[i] == "+")
            {
                opnum1 = opnums.back();
                opnums.pop_back();
                opnums.back() += opnum1;
            }
            else if (tokens[i] == "-")
            {
                opnum1 = opnums.back();
                opnums.pop_back();
                opnums.back() -= opnum1;
            }
            else if (tokens[i] == "*")
            {
                opnum1 = opnums.back();
                opnums.pop_back();
                opnums.back() *= opnum1;
            }
            else if (tokens[i] == "/")
            {
                opnum1 = opnums.back();
                opnums.pop_back();
                opnums.back() /= opnum1;
            }
            else
            {
                opnums.push_back(std::stoi(tokens[i]));
            }
        }
        return opnums.back();
    }
};