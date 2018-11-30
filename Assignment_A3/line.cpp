#include "line.h"
Line::Line(const Coordinate sentCords[])
{
    shapeType = name;
    amountOfCoordinates = 2;
    for (int i = 0; i < amountOfCoordinates; i++)
    {
        cords[i] = sentCords[i];
    }
}

double Line::Area()
{
    return -1;
}

double Line::Circumference()
{
    return 0;
}

Coordinate Line::Position()
{
    double totX = 0;
    double totY = 0;
    for (int i = 0; i < amountOfCoordinates; i++)
    {
        totX += cords[i].GetX();
        totY += cords[i].GetY();
    }
    double centerX = (totX) / amountOfCoordinates;
    double centerY = (totY) / amountOfCoordinates;

    Coordinate centerCord(centerX, centerY);
    return centerCord;
}

bool Line::IsConvex()
{
    return false;
}

Line &Line::operator=(const Line &l)
{
    if (this == &l)
    {
        return *this;
    }

    for (int i = 0; i < amountOfCoordinates; i++)
    {
        cords[i] = l.cords[i];
    }
    return *this;
}

void Line::CopyCoordinates(Coordinate *&cordCopyArr) const
{
    for (int i = 0; i < amountOfCoordinates; i++)
    {
        cordCopyArr[i] = cords[i];
    }
}

std::string Line::CoordinatesToString() const
{
    std::string textToRet = "";

    for (int i = 0; i < amountOfCoordinates; i++)
    {
        double x = round(cords[i].GetX() * 1000) / 1000;
        double y = round(cords[i].GetY() * 1000) / 1000;
        std::stringstream ss;
        ss << "X: " << x << " Y: " << y << '\n';
        textToRet += ss.str();
    }
    return textToRet;
}
