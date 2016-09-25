/*
* Implement function that determines whether a horizontal ray 
* to the right of a point intersects a linear segment.
*
* Avoid using trig library functions.
*/
#include <iostream>
#include <utility>

using namespace std;

typedef pair<long, long> Point;

bool rightRayCrosses(const Point& p, const Point& r1, const Point& r2)
{
    bool rtn;

    if (r1.first <= p.first && r2.first <= p.first)
    {
        // segment is to the left.
        rtn = false;
    }
    else if (r1.second >= p.second && r2.second >= p.second)
    {
        // segment is above.
        rtn = false;
    }
    else if (r1.second <= p.second && r2.second <= p.second)
    {
        // segment is below.
        rtn = false;
    }
    else
    {
        rtn = false;
    }

    return rtn;
}

int main(int argc, char *argv[])
{
    Point p0 = make_pair(5, 7);

    Point rl0 = make_pair(2, 11);
    Point rr0 = make_pair(15, 2);

    cout << "Ray crosses? " << rightRayCrosses(p0, rl0, rr0) << endl;
    
    cout << "Done." << endl;
    return 0;
}
