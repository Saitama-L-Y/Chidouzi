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
	Body body;                 //���������(����Ļ����ʾ��ͼ��)
	int step;                  //�������ж�·���е�λ��
	vector<MoveDir> _route;    //�����ж�·��
};
