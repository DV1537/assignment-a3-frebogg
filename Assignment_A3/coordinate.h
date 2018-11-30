#ifndef COORDINATE_H
#define COORDINATE_H

class Coordinate
{
private:
  double x = 0.0;
  double y = 0.0;

public:
  Coordinate(){};
  Coordinate(double xCord, double yCord);
  double GetX() const;
  double GetY() const;
};

#endif
