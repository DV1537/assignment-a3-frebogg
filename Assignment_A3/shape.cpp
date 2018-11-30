#include "shape.h"
#include "polygon.h"
#include "triangle.h"
#include "line.h"
#include "point.h"

std::string Shape::GetType() const
{
  return shapeType;
}

double Shape::Distance(Shape &s)
{
  Coordinate firstCord = this->Position();
  Coordinate secondCord = s.Position();

  double distance = sqrt((pow((firstCord.GetX() - secondCord.GetX()), 2)) +
                         (pow((firstCord.GetY() - secondCord.GetY()), 2)));
  return distance;
}

/* 
  Note: this function assumes the coordinates are properly ordered before combining.
*/
Shape &Shape::operator+(Shape &s)
{
  if (this == &s)
  {
    return *this;
  }

  int totalCoords = this->amountOfCoordinates + s.amountOfCoordinates;

  Coordinate *allCoords = new Coordinate[totalCoords];
  Coordinate *thisCoordArr = new Coordinate[this->amountOfCoordinates];
  Coordinate *otherCoordArr = new Coordinate[s.amountOfCoordinates];
  this->CopyCoordinates(thisCoordArr);
  s.CopyCoordinates(otherCoordArr);

  // Store this shape's coordinates
  for (int i = 0; i < (this->amountOfCoordinates); i++)
  {
    allCoords[i] = thisCoordArr[i];
  }

  // Store other shape's coordinates
  for (int i = 0; i < (s.amountOfCoordinates); i++)
  {
    int correctIndex = (this->amountOfCoordinates + i);
    allCoords[correctIndex] = otherCoordArr[i];
  }

  Shape *combinedShape = nullptr;

  if (totalCoords <= 3)
  {
    if (totalCoords == 2)
    {
      combinedShape = new Line(allCoords);
    }
    else if (totalCoords == 3)
    {
      combinedShape = new Triangle(allCoords);
    }
  }
  else if (totalCoords > 3)
  {
    combinedShape = new Polygon(allCoords, totalCoords);
  }

  if (combinedShape)
  {
    double area = round(combinedShape->Area() * 1000) / 1000;
    std::cout << "Area of combined shape: " << area << '\n';
    delete combinedShape;
    combinedShape = nullptr;
  }

  delete[] allCoords;
  delete[] thisCoordArr;
  delete[] otherCoordArr;

  allCoords = nullptr;
  thisCoordArr = nullptr;
  otherCoordArr = nullptr;

  return *this;
}

std::ostream &operator<<(std::ostream &out, const Shape &s)
{
  out << s.CoordinatesToString() << '\n';
  return out;
}
