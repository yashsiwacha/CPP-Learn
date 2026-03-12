#include <iostream>

namespace Geometry{
    struct Point{
        int x,y;
    };
    void printPoint(const Point& pt){
        std::cout << "(" << pt.x << ", " << pt.y << ")" << std::endl;
    }
}

namespace G = Geometry;

int main(){
    G::Point p{5,7};
    G::printPoint(p);
    return 0;
}