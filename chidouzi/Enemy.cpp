
#include "Enemy.h"

Enemy::Enemy(Coor bornPos, Map& m, vector<MoveDir>& route, MapUint b) :
	MoveObj(bornPos, m), _route(route), body(b), step(0)
{
}

void Enemy::move()
{
	pos = getNextPos(_route[step]);
	step++;
	step %= _route.size();
}

bool Enemy::Catch(const Player& p)
{
	Coor p_pos = p.getPos();
    Coor upper = { pos.row - 1, pos.col };
    Coor down = { pos.row + 1, pos.col };
    Coor left = { pos.row, pos.col - 1 };
    Coor right = { pos.row, pos.col + 1 };
    return p_pos == upper || p_pos == down || p_pos == left || p_pos == right || p_pos == pos;
}

void Enemy::draw(vector<vector<MapUint>>& buffer)
{
	//����ʾ�������������˵�ͼ��
	//buffer:��ʾ������
	buffer[pos.row][pos.col] = body;
}