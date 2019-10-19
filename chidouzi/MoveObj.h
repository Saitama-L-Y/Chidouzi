#pragma once
#include "Map.h"

enum MoveDir { Up, Down, Left, Right };

class MoveObj
{
public:
    MoveObj() = default;
    MoveObj(Coor bornPos, Map& m);
    virtual ~MoveObj();
	Coor getPos() const;
    virtual void move() = 0;
protected:
	Coor pos;                    //��ǰλ��
	Map *map;
    Coor getNextPos(MoveDir md); //����ƶ������ʱλ��
private:
    //��ֹ�߳���ͼ
    Coor MoveUp();
    Coor MoveDown();
    Coor MoveLeft();
    Coor MoveRight();
};
