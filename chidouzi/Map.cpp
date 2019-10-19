
#include "Map.h"

Map::Map(Coor s, const MapUint *map) :size(s), foodCount(0)
{
    _m.resize(size.row);
    for (int i = 0; i < size.row; i++)
    {
        _m[i].resize(size.col);
        for (int j = 0; j < size.col; j++)
        {
            _m[i][j] = *(map + i * size.col + j);
            if (_m[i][j] == FOOD)
                foodCount++;
        }
    }
}

const vector<MapUint>& Map::operator[](int i)
{
	return _m[i];
}

const vector<vector<MapUint> >& Map::getMap()
{
    return _m;
}

void Map::eatFood(Coor f)
{
    if (_m[f.row][f.col] == FOOD) 
    {
        _m[f.row][f.col] = AIR;
        foodCount--;
    }
}

int Map::getFoodCount()
{
    return foodCount;
}

