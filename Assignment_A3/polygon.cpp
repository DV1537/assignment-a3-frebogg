#include "polygon.h"
Polygon::~Polygon()
{
    if (cords)
    {
        delete[] cords;
        cords = nullptr;
    }
}

Polygon::Polygon(const Coordinate sentCords[], const int amountOfCoordinates)
{
    shapeType = name;
    cords = new Coordinate[amountOfCoordinates];

    for (int i = 0; i < amountOfCoordinates; i++)
    {
        cords[i] = sentCords[i];
    }

    this->amountOfCoordinates = amountOfCoordinates;
}

// Note: this function only works if the vertices are properly ordered.
double Polygon::Area()
{
    if (IsConvex())
    {
        /*
        Solution found here : https://www.geeksforgeeks.org/area-of-a-polygon-with-given-n-ordered-vertices/
        */
        double area = 0;
        int j = amountOfCoordinates - 1;

        for (int i = 0; i < amountOfCoordinates; i++)
        {
            area += (cords[j].GetX() + cords[i].GetX()) * (cords[j].GetY() - cords[i].GetY());
            j = i; // j is previous vertex to i
        }
        area = fabs(area / 2.0);
        if (area > 0)
        {
            return area;
        }
    }
    return -1;
}
// Note: this function only works if the vertices are properly ordered.
double Polygon::Circumference()
{
    double sideSum = 0;
    for (int i = 0; i < amountOfCoordinates; i++)
    {
        if (i == (amountOfCoordinates - 1))
        {
            sideSum += sqrt((pow((cords[i].GetX() - cords[0].GetX()), 2)) +
                            (pow((cords[i].GetY() - cords[0].GetY()), 2)));
        }
        else
        {
            sideSum += sqrt((pow((cords[i].GetX() - cords[i + 1].GetX()), 2)) +
                            (pow((cords[i].GetY() - cords[i + 1].GetY()), 2)));
        }
    }
    return sideSum;
}
Coordinate Polygon::Position()
{
    double xTot = 0;
    double yTot = 0;
    for (int i = 0; i < amountOfCoordinates; i++)
    {
        xTot += cords[i].GetX();
        yTot += cords[i].GetY();
    }

    double centerX = (xTot / amountOfCoordinates);
    double centerY = (yTot / amountOfCoordinates);
    Coordinate centerCord(centerX, centerY);

    return centerCord;
}

// Note: this function only works if the vertices are properly ordered.
bool Polygon::IsConvex()
{
    /*
    ((B.X - A.X) * (C.Y - B.Y) - (B.Y - A.Y) * (C.X - B.X))
    The polygon is convex if all cross products have the same sign 
    Solution found here : https://stackoverflow.com/questions/40738013/how-to-determine-the-type-of-polygon 
    */

    double *crossProductsArr = new double[amountOfCoordinates];

    // Go through all the points and store the crossproduct value
    for (int i = 0; i < (amountOfCoordinates); i++)
    {
        double aX = 0;
        double bX = 0;
        double cX = 0;

        double aY = 0;
        double bY = 0;
        double cY = 0;

        int nextIndex1 = 0;
        int nextIndex2 = 0;

        if (i == (amountOfCoordinates - 2)) // Check with index i+1 and 1
        {
            nextIndex1 = (i + 1);
            nextIndex2 = (0);
        }
        else if (i == (amountOfCoordinates - 1)) // Check with index 0 and 1
        {
            nextIndex1 = (0);
            nextIndex2 = (1);
        }
        else
        {
            nextIndex1 = (i + 1);
            nextIndex2 = (i + 2);
        }

        aX = cords[i].GetX();
        bX = cords[nextIndex1].GetX();
        cX = cords[nextIndex2].GetX();

        aY = cords[i].GetY();
        bY = cords[nextIndex1].GetY();
        cY = cords[nextIndex2].GetY();

        crossProductsArr[i] = ((bX - aX) * (cY - bY) - (bY - aY) * (cX - bX));
    }

    bool isConvex = true;
    bool startingValue = false;

    // Set a starting value of the bool
    if (crossProductsArr[0] >= 0)
    {
        startingValue = false;
    }
    else
    {
        startingValue = true;
    }
    // If the sign of a crossproduct is different from another we break from the loop (not convex)
    for (int i = 1; i < amountOfCoordinates; i++)
    {
        bool temp = startingValue;

        if (crossProductsArr[i] >= 0)
        {
            temp = false;
        }
        else
        {
            temp = true;
        }
        if (temp != startingValue)
        {
            isConvex = false;
            break;
        }
    }
    delete[] crossProductsArr;
    crossProductsArr = nullptr;

    return isConvex;
}

Polygon &Polygon::operator=(const Polygon &p)
{
    if (this == &p)
    {
        return *this;
    }

    // No need to create new
    if (amountOfCoordinates == p.amountOfCoordinates && cords)
    {
        for (int i = 0; i < amountOfCoordinates; i++)
        {
            cords[i] = p.cords[i];
        }
    }
    else
    {
        if (cords)
        {
            delete[] cords;
            cords = nullptr;
        }

        if (amountOfCoordinates != p.amountOfCoordinates)
        {
            amountOfCoordinates = p.amountOfCoordinates;
        }

        cords = new Coordinate[amountOfCoordinates];
        for (int i = 0; i < amountOfCoordinates; i++)
        {
            cords[i] = p.cords[i];
        }
    }
    return *this;
}

Polygon &Polygon::operator+(const Coordinate &c)
{
    amountOfCoordinates += 1;

    Coordinate *tempCordArr = new Coordinate[amountOfCoordinates];

    if (cords)
    {
        for (int i = 0; i < (amountOfCoordinates - 1); i++)
        {
            tempCordArr[i] = cords[i];
        }
        delete[] cords;
        cords = nullptr;
    }

    tempCordArr[amountOfCoordinates - 1] = c;
    cords = tempCordArr;
    return *this;
}

std::string Polygon::CoordinatesToString() const
{
    std::string textToRet = "";

    for (int i = 0; i < amountOfCoordinates; i++)
    {
        double x = round(cords[i].GetX() * 1000) / 1000;
        double y = round(cords[i].GetY() * 1000) / 1000;
        std::stringstream ss;
        ss << "X: " << x << " Y: " << y << '\n';
        textToRet += ss.str();
    }
    return textToRet;
}
void Polygon::CopyCoordinates(Coordinate *&cordCopyArr) const
{
    for (int i = 0; i < amountOfCoordinates; i++)
    {
        cordCopyArr[i] = cords[i];
    }
}
