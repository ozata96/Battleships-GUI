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

    // public:
        // Interaction
        void MakeMove();
        void Fight(vector<string> &enemyGrid);
        void Strike(int row, int col, vector<string> &grid);
        
        // Consequences
        void Miss(int row, int col, vector<string> &grid);
        void Hit(int row, int col, vector<string> &grid);
};

#endif