#include <algorithm>

class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        // Find the closest point on the rectangle to the circle center using clamp logic
        int closestX = std::max(x1, std::min(xCenter, x2));
        int closestY = std::max(y1, std::min(yCenter, y2));
        
        // Calculate the distance components from the circle center to the closest point
        int distX = xCenter - closestX;
        int distY = yCenter - closestY;
        
        // Use squared distance to avoid floating-point square root operations
        int distanceSquared = (distX * distX) + (distY * distY);
        
        // Return true if the squared distance is less than or equal to the squared radius
        return distanceSquared <= (radius * radius);
    }
};