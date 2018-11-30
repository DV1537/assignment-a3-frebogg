#include "functions.h"
bool ValidNumber(const std::string inputToCheck)
{
    bool isValid = true;

    int maxDotCharacters = 1;
    int maxMinusCharacters = 1;

    int currentDotAmount = 0;
    int currentMinusAmount = 0;

    for (int i = 0; i < inputToCheck.length() && isValid == true; i++)
    {
        if (!(isdigit(inputToCheck[i])))
        {
            if (i == 0)
            {
                if (inputToCheck[i] == '-')
                {
                    currentMinusAmount++;
                }
                else
                {
                    isValid = false;
                }
            }
            else
            {
                if (inputToCheck[i] == '.')
                {
                    currentDotAmount++;
                }
                else
                {
                    isValid = false;
                }

                if (isValid && ((currentDotAmount > maxDotCharacters) || (currentMinusAmount > maxMinusCharacters)))
                {
                    isValid = false;
                }
            }
        }
    }
    return isValid;
}

void AddCoordinateToArray(Coordinate *&cArr, double cordX, double cordY, int arrSize)
{
    Coordinate tempCord(cordX, cordY);
    Coordinate *tempArray = new Coordinate[arrSize];
    for (int i = 0; i < (arrSize - 1); i++)
    {
        tempArray[i] = cArr[i];
    }
    tempArray[arrSize - 1] = tempCord;

    if (cArr)
    {
        delete[] cArr;
        cArr = nullptr;
    }
    cArr = tempArray;
}

void SetShape(Shape *&s, const Coordinate *cordArr, const int cordAmount)
{
    if (cordAmount == 1)
    {
        s = new Point(cordArr[0]);
    }
    else if (cordAmount == 2)
    {
        s = new Line(cordArr);
    }
    else if (cordAmount == 3)
    {
        s = new Triangle(cordArr);
    }
    else
    {
        s = new Polygon(cordArr, cordAmount);
    }
}
