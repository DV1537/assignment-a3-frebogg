#include "triangle.h"
Triangle::Triangle(const Coordinate sentCords[])
{
  shapeType = name;
  amountOfCoordinates = 3;
  for (int i = 0; i < amountOfCoordinates; i++)
  {
    cords[i] = sentCords[i];
  }
}

double Triangle ::Area()
{
  double aX = cords[0].GetX();
  double aY = cords[0].GetY();
  double bX = cords[1].GetX();
  double bY = cords[1].GetY();
  double cX = cords[2].GetX();
  double cY = cords[2].GetY();

  // Check if the triangle intersects itself
  if ((aX == bX && aX == cX) || (aY == bY && aY == cY))
  {
    return -1;
  }
  else
  {
    double area = fabs((aX * (bY - cY) + bX * (cY - aY) + cX * (aY - bY)) / 2);
    return area;
  }
}

double Triangle ::Circumference()
{
  double sideSum = 0;
  for (int i = 0; i < (amountOfCoordinates); i++)
  {
    if (i == (amountOfCoordinates - 1))
    {
      sideSum += sqrt((pow((cords[i].GetX() - cords[0].GetX()), 2)) +
                      (pow((cords[i].GetY() - cords[0].GetY()), 2)));
    }
    else
    {
      sideSum += sqrt((pow((cords[i].GetX() - cords[i + 1].GetX()), 2)) +
                      (pow((cords[i].GetY() - cords[i + 1].GetY()), 2)));
    }
  }

  return sideSum;
}

Coordinate Triangle ::Position()
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

bool Triangle::IsConvex()
{
  return true;
}

Triangle &Triangle::operator=(const Triangle &t)
{
  if (this == &t)
  {
    return *this;
  }

  for (int i = 0; i < amountOfCoordinates; i++)
  {
    cords[i] = t.cords[i];
  }
  return *this;
}

void Triangle::CopyCoordinates(Coordinate *&cordCopyArr) const
{
  for (int i = 0; i < amountOfCoordinates; i++)
  {
    cordCopyArr[i] = cords[i];
  }
}

std::string Triangle::CoordinatesToString() const
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