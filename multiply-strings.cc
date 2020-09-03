#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <numeric>

class Solution
{
public:
    static constexpr int toInt(char num) noexcept { return num - '0'; }
    static constexpr char toChar(int num) noexcept { return '0' + num; }

    std::string multiply(const std::string &num1, const std::string &num2)
    {
        return Opt::multiply(num1, num2);
    }

    class VecStr
    {
    public:
        static std::string addStr(const std::string &a, const std::string &b)
        {
            std::string res;
            auto iter1 = a.rbegin(), end1 = a.rend(), iter2 = b.rbegin(), end2 = b.rend();

            int s, c;
            s = c = 0;

            while (iter1 != end1 && iter2 != end2)
            {
                s = toInt(*iter1) + toInt(*iter2) + c;
                c = s / 10;
                res.push_back(toChar(s % 10));
                iter1++;
                iter2++;
            }

            auto iter_last = (iter1 == end1) ? iter2 : iter1;
            auto last_end = (iter_last == iter1) ? end1 : end2;

            while (iter_last != last_end)
            {
                s = toInt(*iter_last) + c;
                c = s / 10;
                res.push_back(toChar(s % 10));
                iter_last++;
            }

            if (c)
                res.push_back(toChar(c));

            return std::string(res.rbegin(), res.rend());
        }

        static std::string multiplyVecStr(const std::string &num1, const std::string &num2)
        {
            std::vector<std::string> str_vec;

            std::string &bigger = const_cast<std::string &>((num1.size() > num2.size()) ? num1 : num2);
            std::string &smaller = const_cast<std::string &>((num1.size() > num2.size()) ? num2 : num1);

            for (int i = smaller.size() - 1; i >= 0; i--)
            {
                int carry = 0;
                int mul = 0;
                std::string mul_res;
                for (int j = bigger.size() - 1; j >= 0; j--)
                {
                    mul = toInt(smaller[i]) * toInt(bigger[j]) + carry;
                    carry = mul / 10;
                    mul_res.push_back(toChar(mul % 10));
                }
                if (carry)
                    mul_res.push_back(toChar(carry));
                str_vec.push_back(std::move(mul_res));
            }

            for (auto &str : str_vec) // erase leading zeros
            {
                while (str.size() > 1 && str.back() == '0')
                    str.pop_back();
                std::reverse(str.begin(), str.end());
            }

            for (int i = 0; i < str_vec.size(); i++) // add zeros
                if (str_vec[i].size() == 1 && str_vec[i][0] == '0')
                    continue;
                else
                    for (int j = 0; j < i; j++)
                        str_vec[i].push_back('0');

            std::string res = str_vec[0];

            for (int i = 1; i < str_vec.size(); i++) // accumulate
                res = addStr(res, str_vec[i]);

            return res;
        }
    };

    class VecDeq
    {
    public:
        static std::deque<char> addDeq(const std::deque<char> &a, const std::deque<char> &b)
        {
            std::deque<char> res;
            auto iter1 = a.rbegin(), end1 = a.rend(), iter2 = b.rbegin(), end2 = b.rend();

            int s, c;
            s = c = 0;

            while (iter1 != end1 && iter2 != end2)
            {
                s = toInt(*iter1) + toInt(*iter2) + c;
                c = s / 10;
                res.push_front(toChar(s % 10));
                iter1++;
                iter2++;
            }

            auto iter_last = (iter1 == end1) ? iter2 : iter1;
            auto last_end = (iter_last == iter1) ? end1 : end2;

            while (iter_last != last_end)
            {
                s = toInt(*iter_last) + c;
                c = s / 10;
                res.push_front(toChar(s % 10));
                iter_last++;
            }

            if (c)
                res.push_front(toChar(c));

            return res;
        }

        static std::string multiplyVecDeq(const std::string &num1, const std::string &num2)
        {
            std::vector<std::deque<char>> str_vec;

            std::string &bigger = const_cast<std::string &>((num1.size() > num2.size()) ? num1 : num2);
            std::string &smaller = const_cast<std::string &>((num1.size() > num2.size()) ? num2 : num1);

            for (int i = smaller.size() - 1; i >= 0; i--)
            {
                int carry = 0;
                int mul = 0;
                std::deque<char> mul_res;
                for (int j = bigger.size() - 1; j >= 0; j--)
                {
                    mul = toInt(smaller[i]) * toInt(bigger[j]) + carry;
                    carry = mul / 10;
                    mul_res.push_front(toChar(mul % 10));
                }
                if (carry)
                    mul_res.push_front(toChar(carry));
                str_vec.push_back(std::move(mul_res));
            }

            for (auto &str : str_vec) // erase leading zeros
                while (str.size() > 1 && str.front() == '0')
                    str.pop_front();

            for (int i = 0; i < str_vec.size(); i++) // add zeros
                if (str_vec[i].size() == 1 && str_vec[i][0] == '0')
                    continue;
                else
                    for (int j = 0; j < i; j++)
                        str_vec[i].push_back('0');

            auto res = str_vec[0];

            for (int i = 1; i < str_vec.size(); i++) // accumulate
                res = std::move(addDeq(res, str_vec[i]));

            return {res.begin(), res.end()};
        }
    };

    class Opt
    {
    public:
        static std::string multiply(std::string num1, std::string num2)
        {
            std::vector<int> res(num1.size() + num2.size() + 1, 0);

            std::reverse(num1.begin(), num1.end());
            std::reverse(num2.begin(), num2.end());

            for (int i = 0; i < num1.size(); i++)
                for (int j = 0; j < num2.size(); j++)
                {
                    res[i + j] += toInt(num1[i]) * toInt(num2[j]);
                    res[i + j + 1] += res[i + j] / 10;
                    res[i + j] %= 10;
                }

            while (res.size() > 1 && res.back() == 0)
                res.pop_back();

            std::string res_str;
            for (int i = res.size() - 1; i >= 0; i--)
                res_str.push_back(toChar(res[i]));
            
            return res_str;
        }
    };
};