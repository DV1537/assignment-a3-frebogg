#ifndef LINE_H
#define LINE_H
#include "shape.h"

class Line : public Shape
{
private:
  Coordinate cords[2];
  const std::string name = "Line";

public:
  Line(const Coordinate sentCords[]);
  double Area() override;
  double Circumference() override;
  bool IsConvex() override;
  std::string CoordinatesToString() const override;
  Coordinate Position() override;
  void CopyCoordinates(Coordinate *&copyCordArr) const override;
  Line &operator=(const Line &l);
};
#endif