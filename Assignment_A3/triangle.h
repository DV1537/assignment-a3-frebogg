#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "shape.h"

class Triangle : public Shape
{
private:
  Coordinate cords[3];
  const std::string name = "Triangle";

public:
  Triangle(const Coordinate sentCords[]);
  double Area() override;
  double Circumference() override;
  Coordinate Position() override;
  bool IsConvex() override;
  std::string CoordinatesToString() const override;
  void CopyCoordinates(Coordinate *&cordCopyArr) const override;
  Triangle &operator=(const Triangle &t);
};

#endif