
#include "Player.h"
#include "main.h"

Player::Player(Coor bornPos, Map & m, MapUint b): MoveObj(bornPos, m), body(b)
{
}

void Player::move()
{
    Coor nextPos;
    MoveDir md;
    Body nextBody = body;
    switch (g_presskey)
    {
    case 'w':
    case 'W':
        md = Up;
        nextBody = 'A';
        break;
    case 's':
    case 'S':
        md = Down;
        nextBody = 'V';
        break;
    case 'a':
    case 'A':
        md = Left;
        nextBody = '<';
        break;
    case 'd':
    case 'D':
        md = Right;
        nextBody = '>';
        break;
    default:
        return;
    }
    body = nextBody;               //改变身体的图案
    nextPos = getNextPos(md);
    MapUint nextStep = (*map)[nextPos.row][nextPos.col];
    switch (nextStep)
    {
    case WALL:
        break;                     //撞墙不移动
    case AIR:
        pos = nextPos;             //空气直接移动
        break;
    case FOOD:
        eat(nextPos);              //碰到食物吃掉
        break;
    default:
        break;
    }
}

void Player::eat(Coor next)
{
    map->eatFood(next);
    pos = next;
}

void Player::draw(vector<vector<MapUint>>& buffer)
{
	//在显示缓冲区里描绘角色的图案
	//buffer:显示缓冲区
	buffer[pos.row][pos.col] = body;
}
