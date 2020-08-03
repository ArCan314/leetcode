class Solution
{
public:
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2)
    {
        int tx_min = x1 - x_center;
        int tx_max = x2 - x_center;
        int ty_min = y1 - y_center;
        int ty_max = y2 - y_center;

        if (ty_max < 0)
        {
            if (tx_min > 0)
                return (tx_min * tx_min + ty_max * ty_max <= radius * radius);
            else if (tx_max > 0)
                return -ty_max <= radius;
            else
                return (tx_max * tx_max + ty_max * ty_max <= radius * radius);
        }
        else if (ty_min < 0)
        {
            if (tx_min > 0)
                return tx_min <= radius;
            else if (tx_max > 0)
                return true;
            else
                return -tx_max <= radius;
        }
        else
        {
            if (tx_min > 0)
                return (tx_min * tx_min + ty_min * ty_min <= radius * radius);
            else if (tx_max > 0)
                return ty_min <= radius;
            else
                return (tx_max * tx_max + ty_min * ty_min <= radius * radius);
        }
    }
};