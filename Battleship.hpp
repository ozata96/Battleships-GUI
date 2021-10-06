class Battleship
{
protected:
    int blocks;
    Battleship(int blocks);
    ~Battleship();

public:
    virtual int GetBlockNumber() = 0;
};

class Flagship : public Battleship
{
public:
    Flagship();
    ~Flagship();
    int GetBlockNumber() override;
};

class Destroyership : public Battleship
{
public:
    Destroyership();
    ~Destroyership();
    int GetBlockNumber() override;
};

class Minorship : public Battleship
{
public:
    Minorship();
    ~Minorship();
    int GetBlockNumber() override;
};

class Radarship : public Battleship
{
public:
    Radarship();
    ~Radarship();
    int GetBlockNumber() override;
};