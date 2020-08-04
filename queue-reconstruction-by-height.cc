#include <vector>
#include <algorithm>
#include <list>

class Solution
{
public:
    std::vector<std::vector<int>> reconstructQueue(std::vector<std::vector<int>> &people)
    {
        return reconstructQueueTallest(people);
    }

    std::vector<std::vector<int>> reconstructQueueSortShortest(std::vector<std::vector<int>> &people) // O(n^2)
    {
        std::vector<std::vector<int>> res(people.size(), std::vector<int>(2, 0));
        std::vector<bool> bitmap(people.size(), false);
        std::sort(people.begin(), people.end(), [](auto &a, auto &b) { return a[0] < b[0]; });
        for (const auto &p : people)
        {
            int count = p[1] + 1;
            for (int i = 0; i < bitmap.size(); i++)
            {
                if (!bitmap[i] || res[i][0] == p[0])
                    count--;
                if (!count)
                {
                    res[i] = p;
                    bitmap[i] = true;
                    break;
                }
            }
        }
        return res;
    }

    std::vector<std::vector<int>> reconstructQueueTallest(std::vector<std::vector<int>> &people)
    {
        if (people.size() < 2)
            return people;
        std::list<std::vector<int>> res;
        std::sort(people.rbegin(), people.rend(),
                  [](auto &a, auto &b) {
                      if (a[0] < b[0])
                          return true;
                      else if (a[0] > b[0])
                          return false;
                      else
                          return a[1] > b[1];
                  });
        int i = 0;
        for (; people[i][0] == people[0][0]; i++)
            res.push_back(people[i]);

        for (; i < people.size(); i++)
        {
            if (people[i][1] == 0)
                res.push_front(people[i]);
            else if (people[i][1] == res.size())
                res.push_back(people[i]);
            else
            {
                int count = people[i][1];
                auto j = res.begin();
                while (j != res.end())
                {
                    if (!count)
                    {
                        res.insert(j, people[i]);
                        break;
                    }
                    j++;
                    count--;
                }
            }
        }

        return std::vector<std::vector<int>>(res.begin(), res.end());
    }
};