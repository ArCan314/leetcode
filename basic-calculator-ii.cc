#include <string>
#include <vector>
#include <cctype>
#include <cassert>

class Solution
{
public:
    int calculate(std::string &s)
    {
        std::vector<int> opnums;
        std::vector<char> ops;
        std::string num_string;
        opnums.push_back(0);

        for (int i = 0; i < s.size(); i++)
        {
            if (std::isdigit(s[i]))
            {
                num_string.push_back(s[i]);
            }
            else if (s[i] != ' ')
            {
                int temp_opnum;
                if (num_string.size())
                {
                    temp_opnum = std::stoi(num_string);

                    num_string.clear();
                    if (ops.size())
                    {
                        if (ops.back() == '*')
                        {
                            opnums.back() *= temp_opnum;
                            ops.pop_back();
                        }
                        else if (ops.back() == '/')
                        {
                            opnums.back() /= temp_opnum;
                            ops.pop_back();
                        }
                        else
                        {
                            opnums.push_back(temp_opnum);
                        }
                    }
                    else
                    {
                        opnums.push_back(temp_opnum);
                    }
                }
                ops.push_back(s[i]);
            }
        }
        int temp_opnum;
        if (num_string.size())
        {
            temp_opnum = std::stoi(num_string);

            if (ops.size())
            {
                if (ops.back() == '*')
                {
                    opnums.back() *= temp_opnum;
                    ops.pop_back();
                }
                else if (ops.back() == '/')
                {
                    opnums.back() /= temp_opnum;
                    ops.pop_back();
                }
                else
                {
                    opnums.push_back(temp_opnum);
                }
            }
            else
            {
                opnums.push_back(temp_opnum);
            }
        }

        while (ops.size())
        {
            char op = ops.back();
            ops.pop_back();
            if (op == '+')
            {
                if (opnums.size() != 1)
                {
                    int temp = opnums.back();
                    opnums.pop_back();
                    opnums.back() += temp;
                }
            }
            else
            {
                if (opnums.size() == 1)
                {
                    opnums.back() *= -1;
                }
                else
                {
                    int temp = opnums.back();
                    opnums.pop_back();
                    opnums.back() -= temp;
                }
            }
        }

        assert(opnums.size() == 1);

        return opnums.front();
    }
};