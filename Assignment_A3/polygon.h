#ifndef POLYGON_H
#define POLYGON_H
#include "shape.h"

class Polygon : public Shape
{
private:
  Coordinate *cords = nullptr;
  const std::string name = "Polygon";

public:
  ~Polygon();
  Polygon(const Coordinate sentCords[], const int amountOfCoordinates);
  double Area() override;
  double Circumference() override;
  bool IsConvex() override;
  Coordinate Position() override;
  void CopyCoordinates(Coordinate *&cordCopyArr) const override;
  std::string CoordinatesToString() const override;
  Polygon &operator=(const Polygon &s);
  Polygon &operator+(const Coordinate &c);
};
#endif