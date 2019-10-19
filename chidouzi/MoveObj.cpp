
#include "MoveObj.h"

MoveObj::MoveObj(Coor bornPos, Map& m) :pos(bornPos), map(&m)
{
}

Coor MoveObj::MoveUp()
{
    Coor next = pos;
    next.row = pos.row - 1 > 0 ? pos.row - 1 : 0;
    return next;
}
Coor MoveObj::MoveDown()
{
    Coor next = pos;
    next.row = pos.row + 1 < map->size.row ? pos.row + 1 : map->size.row;
    return next;
}
Coor MoveObj::MoveLeft()
{
    Coor next = pos;
    next.col = pos.col - 1 > 0 ? pos.col - 1 : 0;
    return next;
}
Coor MoveObj::MoveRight()
{
    Coor next = pos;
    next.col = pos.col + 1 < map->size.col ? pos.col + 1 : map->size.col;
    return next;
}

Coor MoveObj::getNextPos(MoveDir md)
{
    Coor next = pos;
	switch (md)
	{
	case Up:
        next = MoveUp();
		break;
	case Down:
        next = MoveDown();
		break;
	case Left:
        next = MoveLeft();
		break;
	case Right:
        next = MoveRight();
		break;
	default:
		break;
	}
    return next;
}

Coor MoveObj::getPos() const
{
    return pos;
}

MoveObj::~MoveObj()
{
    map = NULL;
}
