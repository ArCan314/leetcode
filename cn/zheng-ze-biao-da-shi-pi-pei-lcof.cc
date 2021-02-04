#include <string>
#include <vector>
#include <deque>
#include <unordered_map>
#include <iostream>
#include <unordered_set>

class NFA
{
public:
    NFA(const std::string &pattern)
    {
        buildNFA(pattern);
    }

    bool match(const std::string &target) const
    {
        int pos = 0;
        std::vector<int> old_states(states_.size(), 0);
        old_states[start_state] = 1;
        std::vector<int> init_null_closure(nullClosure(start_state));
        for (int i = 0; i < states_.size(); i++)
            old_states[i] |= init_null_closure[i];
            
        // std::cout << "\nMatch:" << std::endl;
        // std::cout << "\tInit state: ";
        // for (int i = 0; i < states_.size(); i++)
        //     if (old_states[i])
        //         std::cout << i << ", ";
        // std::cout << std::endl;

        while (pos < target.size())
        {
            std::vector<int> new_states(move(old_states, ToAlphabet(target[pos++])));
            // std::cout << "\tNew state: ";
            // for (int i = 0; i < states_.size(); i++)
            //     if (new_states[i])
            //         std::cout << i << ", ";
            // std::cout << std::endl;
            old_states.swap(new_states);
        }
        // std::cout << "Match Result: " << (old_states[end_state] ? "true" : "false") << std::endl;
        return old_states[end_state];
    }

    void print() const
    {
        std::cout << "State size: " << states_.size() << std::endl;
        std::cout << "Start state = " << start_state << ", end_state = " << end_state << std::endl;
        std::cout << "States_: " << std::endl;
        for (int i = 0; i < states_.size(); i++)
        {
            std::cout << "\tcur_state: " << i << std::endl;
            std::cout << "\taccept: " << std::endl;
            for (const auto &[k, v] : states_[i])
            {
                std::string k_str;
                if (k == Alphabet::null)
                    k_str = "Null";
                else
                {
                    char temp = static_cast<int>(k) + 'a';
                    k_str.push_back(temp);
                }
                std::cout << "\t\t(" << k_str << "," << v << ")" << std::endl;
            }

            std::cout << std::endl;
        }
    }

private:
    enum class Alphabet
    {
        a,
        b,
        c,
        d,
        e,
        f,
        g,
        h,
        i,
        j,
        k,
        l,
        m,
        n,
        o,
        p,
        q,
        r,
        s,
        t,
        u,
        v,
        w,
        x,
        y,
        z,
        null,
        size,
    };
    std::vector<std::unordered_map<Alphabet, int>> states_;
    int start_state{};
    int end_state{};

    std::vector<int> move(const std::vector<int> &states, const Alphabet accept) const
    {
        std::vector<int> res(states_.size(), 0);
        std::vector<int> cur_states(states);
        std::vector<int> null_closure_before(nullClosure(states));
        std::vector<int> accept_states(res);

        for (int i = 0; i < states_.size(); i++)
            cur_states[i] |= null_closure_before[i];

        for (int i = 0; i < states_.size(); i++)
        {
            if (cur_states[i])
            {
                auto iter = states_[i].find(accept);
                if (iter != states_[i].end())
                    accept_states[iter->second] = 1;
            }
        }

        std::vector<int> null_closure_after(nullClosure(accept_states));
        for (int i = 0; i < states_.size(); i++)
            res[i] = accept_states[i] | null_closure_after[i];

        return res;
    }

    std::vector<int> nullClosure(const std::vector<int> &states) const
    {
        std::vector<int> res(states_.size(), 0);
        for (int i = 0; i < states.size(); i++)
        {
            if (states[i])
            {
                auto temp(std::move(nullClosure(i)));
                for (int i = 0; i < res.size(); i++)
                    res[i] |= temp[i];
            }
        }
        return res;
    }

    std::vector<int> nullClosure(int state) const
    {
        std::vector<int> res(states_.size(), 0);
        std::deque<int> expand;
        expand.push_back(state);
        while (!expand.empty())
        {
            int cur_state = expand.front();
            expand.pop_back();
            if (auto iter = states_[cur_state].find(Alphabet::null);
                iter != states_[cur_state].end() && !res[iter->second])
            {
                res[iter->second] = 1;
                expand.push_back(iter->second);
            }
        }
        return res;
    }

    template <typename T>
    static constexpr Alphabet ToAlphabet(const T val)
    {
        assert(false);
        return static_cast<Alphabet>(val);
    }

    static constexpr Alphabet ToAlphabet(const char val)
    {
        return static_cast<Alphabet>(val - 'a');
    }

    void buildNFA(const std::string &pattern)
    {
        states_.emplace_back();
        start_state = 0;
        for (int i = 0; i < pattern.size(); i++)
        {
            int cur_state = states_.size() - 1;
            bool has_kleene_star = false;
            char cur_char = pattern[i];
            if (i + 1 < pattern.size() && pattern[i + 1] == '*')
            {
                has_kleene_star = true;
                i++;
            }

            int next_state = states_.size();
            states_.emplace_back();

            if (has_kleene_star)
            {
                states_[cur_state][Alphabet::null] = next_state;
                if (cur_char == '.')
                    for (char i = 'a'; i <= 'z'; i++)
                        states_[cur_state][ToAlphabet(i)] = cur_state;
                else
                    states_[cur_state][ToAlphabet(cur_char)] = cur_state;
            }
            else
            {
                if (cur_char == '.')
                    for (char i = 'a'; i <= 'z'; i++)
                        states_[cur_state][ToAlphabet(i)] = next_state;
                else
                    states_[cur_state][ToAlphabet(cur_char)] = next_state;
            }
        }
        end_state = states_.size() - 1;
    }
};

class Solution
{
public:
    bool isMatch(const std::string &s, const std::string &p)
    {
        NFA nfa(p);
        // nfa.print();
        return nfa.match(s);
    }
};