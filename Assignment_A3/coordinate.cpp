#include "coordinate.h"
Coordinate ::Coordinate(double xCord, double yCord)
{
    x = xCord;
    y = yCord;
}
double Coordinate::GetY() const
{
    return y;
}
double Coordinate::GetX() const
{
    return x;
}