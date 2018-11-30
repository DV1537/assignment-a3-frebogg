#include "functions.h"

int main(int argc, const char *argv[])
{
    if (argc > 1)
    {
        std::ifstream myReadFile;
        myReadFile.open(argv[1]);

        if (myReadFile)
        {
            std::string line = "";
            int shapeCount = 0;
            int arrSize = 0;
            int amountOfCoordinates = 0;
            Coordinate *cordArr = new Coordinate[arrSize];

            Shape *firstShape = nullptr;
            Shape *secondShape = nullptr;

            while ((getline(myReadFile, line) && (shapeCount < 2)))
            {
                double cordX = 0.0;
                double cordY = 0.0;

                int coordCounter = 0;

                std::istringstream iss(line);
                std::string currentText = "";
                while (iss >> currentText)
                {
                    if (ValidNumber(currentText))
                    {
                        double readNr = stod(currentText);
                        coordCounter += 1;

                        // Create a coordinate for every 2nd value
                        if ((coordCounter % 2) == 0)
                        {
                            cordY = readNr;
                            arrSize += 1;

                            AddCoordinateToArray(cordArr, cordX, cordY, arrSize);
                            amountOfCoordinates += 1;
                        }
                        else if ((coordCounter % 2) != 0)
                        {
                            cordX = readNr;
                        }
                    }
                    else
                    {
                        return 1;
                    }
                }

                // Invalid coordinate
                if ((coordCounter % 2) != 0)
                {
                    return 1;
                }
                else if (amountOfCoordinates > 0 && ((coordCounter % 2) == 0))
                {
                    if (shapeCount == 0)
                    {
                        SetShape(firstShape, cordArr, amountOfCoordinates);
                        amountOfCoordinates = 0;
                        arrSize = 0;
                    }

                    else if (shapeCount == 1)
                    {
                        SetShape(secondShape, cordArr, amountOfCoordinates);
                    }

                    if (cordArr)
                    {
                        delete[] cordArr;
                        cordArr = nullptr;
                    }
                    shapeCount += 1;
                }
            }

            myReadFile.close();

            // If two shapes were created properly we combine
            if (firstShape && secondShape)
            {
                *firstShape + *secondShape; // Overloaded "+" operator for combining shapes

                delete firstShape;
                firstShape = nullptr;

                delete secondShape;
                secondShape = nullptr;
            }
            else
            {
                return 1;
            }
            return 0;
        }
        else
        {
            return 1;
        }
    }
}
