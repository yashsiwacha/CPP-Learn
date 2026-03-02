#include <iostream>
using namespace std;

class Box
{
private:
    double length;
    double width;
    double height;

public:
    Box(double length, double width, double height)
        : length(length), width(width), height(height) {}

    // Friend function gets controlled access to private members.
    friend double volume(const Box &b);
};

double volume(const Box &b)
{
    return b.length * b.width * b.height;
}

int main()
{
    Box box(2.0, 3.0, 4.0);

    double boxVolume = volume(box);
    cout << "Volume of box: " << boxVolume << '\n';

    return 0;
}
