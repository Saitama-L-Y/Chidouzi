
#include "main.h"

void mission1()
{
    const MapUint pass[9][26] = {
    "*************************",
    "** . . . . . . . . . . **",
    "** .** . ************. **",
    "** .** . . . . . . **. **",
    "** .** . ******* . **. **",
    "** .** . . . . . . **. **",
    "** .************ . **. **",
    "** . . . . . . . . . . **",
    "*************************"
    };
    map = Map({ 9, 26 }, (const MapUint*)pass);

    vector<MoveDir> route[4];
    route[0] = vector<MoveDir>(10, Right);
    route[1] = vector<MoveDir>(2, Up);
    route[2] = vector<MoveDir>(10, Left);
    route[3] = vector<MoveDir>(2, Down);
    for (int i = 1; i < 4; i++)
        route[0].insert(route[0].end(), route[i].begin(), route[i].end());
    enemys.clear();
    vector<Enemy>().swap(enemys);
    enemys.resize(1);
    enemys[0] = Enemy({ 5,7 }, map, route[0]);

    player = Player({ 1,2 }, map);

}

void mission2()
{
    cout << "mission2" << endl;
    g_status = Win;
}

void mission3()
{
    cout << "mission3" << endl;
    g_status = Win;
}
