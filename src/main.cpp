/*
* Calling shell to evaluate "rayCrosses" method.
*/
#include <geom.h>

#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    Point p0 = make_pair(5, 7);

    Point rl0 = make_pair(2, 11);
    Point rr0 = make_pair(15, 2);

    cout << "Determine if horizontal ray from (" << p0.first << "," << p0.second << ") croses segment, " << endl;
    cout << "    (" << rl0.first << "," << rl0.second << ") - (" << rr0.first << "," << rr0.second << ")" << endl;
    cout << "Ray crosses? " << rightRayCrosses(p0, rl0, rr0) << endl;
    
    cout << "Done." << endl;
    return 0;
}
