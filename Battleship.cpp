#include "Battleship.hpp"

// Mother Class
Battleship::Battleship(int blocks) : blocks(blocks){};
Battleship::~Battleship(){};


// Child 1
Flagship::Flagship() : Battleship(blocks){blocks = 5;};
Flagship::~Flagship(){};
int Flagship::GetBlockNumber(){return blocks;};

// Child 2
Destroyership::Destroyership() : Battleship(blocks){blocks = 4;};
Destroyership::~Destroyership(){};
int Destroyership::GetBlockNumber(){return blocks;};

// Child 3
Minorship::Minorship() : Battleship(blocks){blocks = 3;};
Minorship::~Minorship(){};
int Minorship::GetBlockNumber(){return blocks;};

// Child 4
Radarship::Radarship() : Battleship(blocks){blocks = 2;};
Radarship::~Radarship(){};
int Radarship::GetBlockNumber(){return blocks;};
