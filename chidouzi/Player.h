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
	Body body;                 //��ҿ��ƵĽ�ɫ������(����Ļ����ʾ��ͼ��)
	void eat(Coor next);
};