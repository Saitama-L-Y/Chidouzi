#include "Boss.h"

Boss::Boss(Coor bornPos, Map &m, vector<MoveDir> &route, MapUint b, int size)
	:Enemy(bornPos, m, route, b), _size(size)
{
}

void Boss::draw(vector<vector<MapUint>>& buffer)
{
	//����ʾ�����������Boss��ͼ��
	//Bossռ��_size*_size����ͼ��λ
	for (int i = 0; i < _size; i++)
		for (int j = 0; j < _size; j++)
			buffer[pos.row + i][pos.col + j] = body;
}

bool Boss::Catch(const Player & p)
{
	Coor p_pos = p.getPos();

	//Boss�������Enemy�����ץȡ�ķ�ΧҲ��
	for (int x = -1; x <= _size; x++)
		for (int y = -1; y <= _size; y++)
		{
			if ((x == -1 && y == -1) || (x == -1 && y == _size)
				|| (x == _size && y == -1) || (x == _size && y == _size))
				continue;     //4���Խǵ����겻�ж�
			Coor c = { pos.row + x, pos.col + y };
			if (p_pos == c)
				return true;
		}
	return false;
}

