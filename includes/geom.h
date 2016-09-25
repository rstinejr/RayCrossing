#ifndef MY_GEOM_H_
#define MY_GEOM_H_
/*
* Implement function that determines whether a horizontal ray 
* to the right of a point intersects a linear segment.
*
* Avoid using trig library functions.
*/
#include <utility>


typedef std::pair<long, long> Point;

/*
* Law of cosines: a**2 = b**2 + c**2 - 2bc(cos(alpha))
*
* For polar cosine, segment c is a ray to the right of length one. 
*
*  So we have: cos(alpha) = (a**2 - b**2 - 1)/(-2ab)
*
*/
double polarCosine(const Point& origin, const Point& p2);

/**
* Given a point and a finite segment, does a ray extending horizontally
* from the right of the point intersect the ray?
*/
bool rightRayCrosses(const Point& p, const Point& r1, const Point& r2);

#endif
