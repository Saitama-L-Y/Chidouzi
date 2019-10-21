#include "Boss.h"

Boss::Boss(Coor bornPos, Map &m, vector<MoveDir> &route, MapUint b, int size)
	:Enemy(bornPos, m, route, b), _size(size)
{
}

void Boss::draw(vector<vector<MapUint>>& buffer)
{
	//在显示缓冲区里描绘Boss的图案
	//Boss占据_size*_size个地图单位
	for (int i = 0; i < _size; i++)
		for (int j = 0; j < _size; j++)
			buffer[pos.row + i][pos.col + j] = body;
}

bool Boss::Catch(const Player & p)
{
	Coor p_pos = p.getPos();

	//Boss的身体比Enemy大，因此抓取的范围也大
	for (int x = -1; x <= _size; x++)
		for (int y = -1; y <= _size; y++)
		{
			if ((x == -1 && y == -1) || (x == -1 && y == _size)
				|| (x == _size && y == -1) || (x == _size && y == _size))
				continue;     //4个对角的坐标不判断
			Coor c = { pos.row + x, pos.col + y };
			if (p_pos == c)
				return true;
		}
	return false;
}

