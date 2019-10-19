#pragma once
#include <vector>
using namespace std;

struct Coor
{
    int row;
    int col;
    bool operator==(Coor& c) const {
        return c.row == row && c.col == col;
    }
};

using MapUint = char;

const MapUint WALL = '*';
const MapUint AIR = ' ';
const MapUint FOOD = '.';

class Map
{
public:
    Coor size;
    Map() = default;
	Map(Coor s, const MapUint *map);
    int getFoodCount();
    void eatFood(Coor f);
	const vector<MapUint>& operator[](int i);
    const vector<vector<MapUint> >& getMap();
private:
    int foodCount;
	vector<vector<MapUint> > _m;
};
