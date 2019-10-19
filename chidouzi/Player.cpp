
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
    body = nextBody;               //�ı������ͼ��
    nextPos = getNextPos(md);
    MapUint nextStep = (*map)[nextPos.row][nextPos.col];
    switch (nextStep)
    {
    case WALL:
        break;                     //ײǽ���ƶ�
    case AIR:
        pos = nextPos;             //����ֱ���ƶ�
        break;
    case FOOD:
        eat(nextPos);              //����ʳ��Ե�
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
	//����ʾ������������ɫ��ͼ��
	//buffer:��ʾ������
	buffer[pos.row][pos.col] = body;
}
