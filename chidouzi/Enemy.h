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
	virtual bool Catch(const Player& p);
	virtual void draw(vector<vector<MapUint> >& buffer);
protected:
	Body body;                 //���������(����Ļ����ʾ��ͼ��)
	int step;                  //�������ж�·���е�λ��
	vector<MoveDir> _route;    //�����ж�·��
};
