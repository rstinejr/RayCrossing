/*
* Implement function that determines whether a horizontal ray 
* to the right of a point intersects a linear segment.
*
* Avoid using trig library functions.
*/
#include <cmath>
#include <iostream>
#include <utility>

using namespace std;

typedef pair<long, long> Point;

/*
* Law of cosines: a**2 = b**2 + c**2 - 2bc(cos(alpha))
*
* For polar cosine, segment c is a ray to the right of length one. 
*
*  So we have: cos(alpha) = (a**2 - b**2 - 1)/(-2ab)
*
*/
double polarCosine(const Point& origin, const Point& p2)
{
   Point synth = make_pair(1, 0);
   Point rmt   = make_pair(p2.first - origin.first, p2.second - origin.second);

   long aSquared = (rmt.second * rmt.second) + (rmt.first - 1) * (rmt.first - 1);
   long bSquared = (rmt.second * rmt.second) + (rmt.first * rmt.first);
   double b        = sqrt((double) bSquared);


   return -1.0 * ((double)(aSquared - bSquared - 1)) /(2.0 * b); 
}

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
        Point lower, higher;

        if (r1.second < r2.second)
        {
            lower = r1;
            higher = r2;
        }
        else
        {
            lower  = r2;
            higher = r1;
        }                 
        double polarRay = polarCosine(lower, higher);
        double polarPt  = polarCosine(lower, p);

        cout << "Polar cosine of ray: " << polarRay << ", of point: " << polarPt << endl;

        if (lower.first > p.first)
        {
            rtn = polarPt > polarRay;
        }
        else
        {
            rtn = polarRay > polarPt;
        }
    }

    return rtn;
}

int main(int argc, char *argv[])
{
    Point orig = make_pair(2, 2);
    Point rmt  = make_pair(3, 3);

    double polarCos = polarCosine(orig, rmt);

    cout << "Polar cosine, (2,2) - (3,3): " << polarCos << endl;

    rmt = make_pair(1, 3);
    cout << "Polar cosine, (2,2) - (1,3): " << polarCosine(orig, rmt) << endl;

    Point p0 = make_pair(5, 7);

    Point rl0 = make_pair(2, 11);
    Point rr0 = make_pair(15, 2);

    cout << "Ray crosses? " << rightRayCrosses(p0, rl0, rr0) << endl;
    
    cout << "Done." << endl;
    return 0;
}
