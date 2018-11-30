#include "point.h"

Point::Point(const Coordinate c1)
{
    shapeType = name;
    amountOfCoordinates = 1;
    cords[0] = c1;
}

double Point::Area()
{
    return -1;
}
double Point::Circumference()
{
    return 0;
}

Coordinate Point::Position()
{
    return cords[0];
}

bool Point::IsConvex()
{
    return false;
}

Point &Point::operator=(const Point &p)
{
    if (this == &p)
    {
        return *this;
    }

    cords[0] = p.cords[0];
    return *this;
}

std::string Point::CoordinatesToString() const
{
    std::string textToRet = "";

    double x = round(cords[0].GetX() * 1000) / 1000;
    double y = round(cords[0].GetY() * 1000) / 1000;
    std::stringstream ss;
    ss << "X: " << x << " Y: " << y << '\n';
    textToRet += ss.str();

    return textToRet;
}

void Point::CopyCoordinates(Coordinate *&cordCopyArr) const
{
    cordCopyArr[0] = cords[0];
}
