#include <string>
#include <vector>
#include <map>
#include <iostream>

struct Customer
{
    std::string start = "";
    std::string end = "";
    int start_time = -1;
    int end_time = -1;
};

class UndergroundSystem
{
public:
    void checkIn(int id, const std::string &stationName, int t)
    {
        auto &temp = _customer[id];
        temp.start = stationName;
        temp.start_time = t;
    }

    void checkOut(int id, const std::string &stationName, int t)
    {
        auto &temp = _customer[id];
        if (temp.start_time != -1)
        {
            if (temp.end_time != -1)
            {
                _start_end_time[{temp.start, temp.end}].first -= 1;
                _start_end_time[{temp.start, temp.end}].second -= temp.end_time - temp.start_time;
            }

            temp.end = stationName;
            temp.end_time = t;

            _start_end_time[{temp.start, temp.end}].first += 1;
            _start_end_time[{temp.start, temp.end}].second += temp.end_time - temp.start_time;
        }
        else
        {
            temp.end = stationName;
            temp.end_time = t;
        }
    }

    double getAverageTime(const std::string &startStation, const std::string &endStation) const
    {
        const auto &temp = _start_end_time.at({startStation, endStation});
        double res = 0.0;
        if (temp.first)
        {
            res = (double)temp.second / temp.first;
        }

        return res;
    }

private:
    std::map<int, Customer> _customer;
    std::map<std::pair<std::string, std::string>, std::pair<int, int>> _start_end_time; // {size, total}
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */