#pragma once
#include "Enemy.h"

class Boss:public Enemy
{
public:
	Boss(Coor bornPos, Map& m, vector<MoveDir>& route, MapUint b = '&', int size = 2);
	bool Catch(const Player& p);
	void draw(vector<vector<MapUint> >& buffer);
protected:
	int _size;
};
