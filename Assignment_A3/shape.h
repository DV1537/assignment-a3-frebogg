#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <string>
#include <cmath>
#include "coordinate.h"
#include <sstream>

class Shape
{
private:
  friend std::ostream &operator<<(std::ostream &out, const Shape &p); // Not part of class, not affected by specifiers.

protected:
  std::string shapeType = "";
  int amountOfCoordinates = 0;

public:
  std::string GetType() const;
  virtual double Area() = 0;
  virtual double Circumference() = 0;
  virtual Coordinate Position() = 0;
  virtual bool IsConvex() = 0;
  virtual std::string CoordinatesToString() const = 0;
  virtual void CopyCoordinates(Coordinate *&copyCordArr) const = 0;
  double Distance(Shape &s);
  Shape &operator+(Shape &s);
};
#endif