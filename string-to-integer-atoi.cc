#include <string>
#include <cctype>

struct ParsePayload
{
    std::string str;
    bool is_neg = false;
    bool is_suc = true;
};

class Solution {
public:

    ParsePayload parse(const std::string &in)
    {
        int state = 0;
        int ind = 0;
        ParsePayload payload{};

        while (payload.is_suc && ind < in.size())
        {
            switch (state)
            {
            case 0:
                if (in[ind] == ' ')
                {
                    state = 1;
                }
                else if (std::isdigit(in[ind]))
                {
                    payload.str.push_back(in[ind]);
                    state = 2;
                }
                else if (in[ind] == '+' || in[ind] == '-')
                {
                    state = 3;
                    payload.is_neg = in[ind] == '-';
                }
                else
                {
                    payload.is_suc = false;
                }
                break;
            case 1:
                if (in[ind] == ' ')
                {
                    ;
                }
                else if (std::isdigit(in[ind]))
                {
                    payload.str.push_back(in[ind]);
                    state = 2;
                }
                else if (in[ind] == '+' || in[ind] == '-')
                {
                    state = 3;
                    payload.is_neg = in[ind] == '-';
                }
                else
                {
                    payload.is_suc = false;
                }
                break;
            case 2:
                if (std::isdigit(in[ind]))
                {
                    payload.str.push_back(in[ind]);
                }
                else
                {
                    state = 4;
                }
                break;
            case 3:
                if (std::isdigit(in[ind]))
                {
                    payload.str.push_back(in[ind]);
                    state = 2;
                }
                else
                {
                    payload.is_suc = false;
                }
                break;
            case 4:
                break;
            default:
                break;
            }

            ind++;
        }

        return payload;
    }

    void removeForwardZero(std::string &str)
    {
        std::string res;
        int i = 0;
        while (i < str.size() && str[i] == '0')
            i++;
        
        for (; i < str.size(); i++)
        {
            res.push_back(str[i]);
        }

        str.swap(res);
    }

    bool check(ParsePayload &payload)
    {
        if (!payload.is_suc)
            return false;
        
        constexpr char kIntMinStr[] = "2147483648";
        constexpr char kIntMaxStr[] = "2147483647";

        std::string zero_str;
        while (zero_str.size() + payload.str.size() < 10)
            zero_str.push_back('0');

        payload.str = zero_str + payload.str;

        if (payload.is_neg)
        {
            if (payload.str.size() > 10)
                payload.str = std::string(kIntMinStr);
            else
                payload.str = std::min(std::string(kIntMinStr), payload.str);
        }
        else
        {
            if (payload.str.size() > 10)
                payload.str = std::string(kIntMaxStr);
            else
                payload.str = std::min(std::string(kIntMaxStr), payload.str);
        }


        removeForwardZero(payload.str);
        if (!payload.str.size())
        {
            payload.str.push_back('0');
        }
        // std::cout << payload.str << std::endl;
        return true;
    }

    int toInt(const ParsePayload &payload)
    {
        long long res = std::stoll(payload.str) * (payload.is_neg ? -1 : 1);
        return static_cast<int>(res);
    }

    int myAtoi(std::string &str) {
        auto payload = parse(str);
        removeForwardZero(payload.str);
        if (check(payload))
        {
            return toInt(payload);
        }
        else
        {
            return 0;
        }
    }
};