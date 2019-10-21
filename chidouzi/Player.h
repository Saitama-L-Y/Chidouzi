#pragma once
#include "MoveObj.h"

class Player :public MoveObj
{
public:
	using Body = MapUint;
    Player() = default;
    Player(Coor bornPos, Map& m, MapUint b = '>');
    void move();
	void draw(vector<vector<MapUint> >& buffer);
protected:
	Body body;                 //玩家控制的角色的身体(在屏幕上显示的图案)
	void eat(Coor next);
};