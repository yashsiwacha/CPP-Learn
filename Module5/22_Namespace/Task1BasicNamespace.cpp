#include <iostream>

// A namespace groups related code and helps avoid naming conflicts.
namespace Geometry
{
    struct Point
    {
        int x, y;
    };

    void printPoint(const Point &pt)
    {
        std::cout << "Point coordinates: (" << pt.x << ", " << pt.y << ")" << std::endl;
    }
}

int main()
{
    // Scope resolution (::) is used to access members inside Geometry.
    Geometry::Point p{3, 4};
    Geometry::printPoint(p);
    return 0;
}
