#include <iostream>
#include <list>

const int MaxCoord = 8;
const int MinCoord = 1;

void CalculatePlusPlusCoords(int firstCoord, int secondCoord, std::list<int>& coordsVector) {
    if (firstCoord < MaxCoord && secondCoord < MaxCoord)
    {
        coordsVector.push_back(firstCoord + 1);
        coordsVector.push_back(secondCoord + 1);
        CalculatePlusPlusCoords(firstCoord + 1, secondCoord + 1, coordsVector);
    }
}

void CalculatePlusMinusCoords(int firstCoord, int secondCoord, std::list<int>& coordsVector) {
    if (firstCoord < MaxCoord && secondCoord > MinCoord)
    {
        coordsVector.push_back(firstCoord + 1);
        coordsVector.push_back(secondCoord - 1);
        CalculatePlusMinusCoords(firstCoord + 1, secondCoord - 1, coordsVector);
    }
}

void CalculateMinusPlusCoords(int firstCoord, int secondCoord, std::list<int>& coordsVector) {
    if (firstCoord > MinCoord && secondCoord < MaxCoord)
    {
        coordsVector.push_back(firstCoord - 1);
        coordsVector.push_back(secondCoord + 1);
        CalculateMinusPlusCoords(firstCoord - 1, secondCoord + 1, coordsVector);
    }
}

void CalculateMinusMinusCoords(int firstCoord, int secondCoord, std::list<int>& coordsVector) {
    if (firstCoord > MinCoord && secondCoord > MinCoord)
    {
        coordsVector.push_back(firstCoord - 1);
        coordsVector.push_back(secondCoord - 1);
        CalculateMinusMinusCoords(firstCoord - 1, secondCoord - 1, coordsVector);
    }
}

std::list<int> CalculateCoords(int firstCoord, int secondCoord) {
    std::list<int> coordsVector;
    CalculatePlusPlusCoords(firstCoord, secondCoord, coordsVector);
    CalculatePlusMinusCoords(firstCoord, secondCoord, coordsVector);
    CalculateMinusPlusCoords(firstCoord, secondCoord, coordsVector);
    CalculateMinusMinusCoords(firstCoord, secondCoord, coordsVector);
    return coordsVector;
}

int GetIntInput() {
    int x;
    std::cout << "Type a coord: ";
    std::cin >> x;
    return x;
}

void PrintCoords(std::list<int> coordsVector) {
    int x = 1;
    for (int n : coordsVector) {

        if (x == 1)
        {
            std::cout << "\n" << n;
            x = 2;
        } else if (x == 2)
        {
            std::cout << " : " << n;
            x = 1;
        }
    }   
}

int main()
{
    PrintCoords(CalculateCoords(GetIntInput(), GetIntInput()));
}
