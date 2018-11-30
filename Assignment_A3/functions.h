#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <fstream>
#include "point.h"
#include "line.h"
#include "triangle.h"
#include "polygon.h"

bool ValidNumber(const std::string inputToCheck); // Checks if it's a real number
void AddCoordinateToArray(Coordinate *&cArr, double cordX, double cordY, int arrSize);
void SetShape(Shape *&s, const Coordinate *cordArr, const int cordAmount);
#endif