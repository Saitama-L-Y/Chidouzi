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
	Coor pos;                    //当前位置
	Map *map;
    Coor getNextPos(MoveDir md); //获得移动后的临时位置
private:
    //防止走出地图
    Coor MoveUp();
    Coor MoveDown();
    Coor MoveLeft();
    Coor MoveRight();
};
