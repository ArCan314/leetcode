#include <string>
#include <vector>

class Solution
{
public:
    static std::vector<int> transVerToVec(const std::string &version)
    {
        std::vector<int> ver;
        int cur = 0;
        while (cur < version.size())
        {
            std::string temp;
            for (; cur < version.size(); cur++)
            {
                if (version[cur] == '.')
                {
                    cur++;
                    break;
                }
                temp.push_back(version[cur]);
            }
            ver.push_back(std::stoi(temp));
        }

        while (ver.back() == 0 && ver.size() > 1)
            ver.pop_back();

        return ver;
    }

    int compareVersion(std::string version1, std::string version2)
    {
        std::vector<int> ver1(transVerToVec(version1)), ver2(transVerToVec(version2));

        int res = 0;
        for (int i = 0; i < ver1.size() && i < ver2.size() && !res; i++)
        {
            if (ver1[i] < ver2[i])
                res = -1;
            else if (ver1[i] > ver2[i])
                res = 1;
        }

        if (!res)
        {
            if (ver1.size() > ver2.size())
                res = 1;
            else if (ver1.size() < ver2.size())
                res = -1;
        }

        return res;
    }
};