#include "Point.hpp"
#include <cmath>

bool bsp(const Point a, const Point b, const Point c, const Point point)
{
   float ax = a.getX().toFloat(); 
   float ay = a.getY().toFloat(); 
   float bx = b.getX().toFloat(); 
   float by = b.getY().toFloat(); 
   float cx = c.getX().toFloat(); 
   float cy = c.getY().toFloat();

   float px = point.getX().toFloat();
   float py = point.getY().toFloat(); 

    float areaABC = 0.5 *fabs(ax*(by-cy) + bx*(cy-ay) + cx*(ay-by));
    
    float areaABP = 0.5 *fabs(ax*(by-py) + bx*(py-ay) + px*(ay-by));
    float areaACP = 0.5 *fabs(ax*(py-cy) + px*(cy-ay) + cx*(ay-py));
    float areaBCP = 0.5 *fabs(px*(by-cy) + bx*(cy-py) + cx*(py-by));

    float areaTotal = areaABP + areaACP + areaBCP;

    if (!areaABP || !areaACP || !areaBCP)
        return false;
    if (areaTotal - areaABC != 0)
        return false;
    return true;
}