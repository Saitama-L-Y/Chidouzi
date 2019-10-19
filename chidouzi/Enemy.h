#pragma once
#include "MoveObj.h"
#include "Player.h"

class Enemy :public MoveObj
{
public:
	using Body = MapUint;
    Enemy() = default;
	Enemy(Coor bornPos, Map& m, vector<MoveDir>& route, MapUint b = '!');
	void move();
	bool Catch(const Player& p);
	void draw(vector<vector<MapUint> >& buffer);
private:
	Body body;                 //怪物的身体(在屏幕上显示的图案)
	int step;                  //怪物在行动路线中的位置
	vector<MoveDir> _route;    //怪物行动路线
};
