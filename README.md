## Ray Crossing Project

This project is a little fun with geometry.  I as puzzling over the issue of how to determine whether or not
a point is within a simple polygog or outside of it.

I did not come up with an answer on my own, but Google suggests that one approach is to extend a ray in any direction from the point
and count the number of times the ray crosses the polygon's border.  An odd number indicates that the point is interior, while
even indicates that the point is exterior. 

(For this exercise, we ignore the issue of points on the border.)

So.... how do you tell whether a ray crosses a line?  And to simplify calculations, let's work with a ray that is a horizontal line
extending to the right from the point in question.

For starters, we know that if both endpoints of the sement are above the point, then the horizontal ray will pass under the segment
without intersecting it.  The ray will also miss if point endpoints are below the point, or both to the right of the point.

Some points in the remaining horizontal strip would emit rays that intersect the segment, but not all.  So how do we distinguish 
sheep from goats?

Here I borrowed from the [Grahm scan algorithm](https://en.wikipedia.org/wiki/Graham_scan). One of the points of the segment will be 
as lower than the other. From this point, if sweeping from the remote endpoint to the test point is a clockwise motion, then the point
is to the right of the segment, and a horizontal ray from it will miss.  But if the point is to the left of the segment, then the 
ray will intersect.

We can determine whether the segment endpoint is clockwise or counterwise from the point in question by computing the "polar cosine" 
to each. The greater the cosine, the more to the right.

### Buiding

After checkinig out the code, ```make all``` compiles, ```make run``` compiles and executes main, ```make clean``` deletes object files
and the executable created by ```make all```.

This project was created on 64-bit Mint 17.2, *rafaela*.  The compiler was g++ (Ubuntu 4.9.3-8ubuntu2~14.04) 4.9.3.
