#ifndef POINT_H
#define POINT_H
#include "shape.h"

class Point : public Shape
{
private:
  Coordinate cords[1];
  const std::string name = "Point";

public:
  Point(const Coordinate c1);
  double Area() override;
  double Circumference() override;
  bool IsConvex() override;
  std::string CoordinatesToString() const override;
  Coordinate Position() override;
  void CopyCoordinates(Coordinate *&cordCopyArr) const override;
  Point &operator=(const Point &p);
};
#endif