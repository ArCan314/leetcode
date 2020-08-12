#include <vector>

class NestedInteger
{
public:
    bool isInteger() const;
    int getInteger() const;
    const std::vector<NestedInteger> &getList() const;
};

#include <vector>
#include <utility>

class NestedIterator
{
public:
    NestedIterator(std::vector<NestedInteger> &nestedList)
    {
        init(nestedList);
    }

    int next()
    {
        return vec[pos++];
    }

    bool hasNext()
    {
        return pos < static_cast<int>(vec.size());
    }

private:
    std::vector<int> vec;
    int pos{0};

    void init(const std::vector<NestedInteger> &nestedList)
    {
        for (int i = 0; i < nestedList.size(); i++)
        {
            auto &nested_int = nestedList[i];
            if (nested_int.isInteger())
                vec.push_back(nested_int.getInteger());
            else
                init(nested_int.getList());
        }
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */