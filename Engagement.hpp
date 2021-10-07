#ifndef Engagement_HPP
#define Engagement_HPP

#include <vector>
#include <iostream>

#include "BoardDisplay.hpp"
#include "ShipPlacement.hpp"

using namespace std;

class Engagement
{
public:
    Engagement();
    ~Engagement();

    int ConvertRow(int row);
    int ConvertCol(int col);

    // public:
    // Interaction
    void MakeMove();
    void Strike(int row, int col, vector<string> &grid, vector<string> &display);

    // Consequences
    void Miss(int row, int col, vector<string> &grid);
    void Hit(int row, int col, vector<string> &grid);
};

#endif