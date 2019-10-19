
#include "main.h"

void keyPress()
{
    while (g_status != Quit) {
        if (_kbhit())
            g_presskey = _getch();
    }
}

void display()
{
    while (g_status == Playing)
    {
        //¥¥Ω®œ‘ æª∫≥Â«¯
        vector<vector<MapUint> > buffer(map.getMap());
		player.draw(buffer);
		for (int k = 0; k < enemys.size(); k++)
			enemys[k].draw(buffer);

        //À¢–¬∆¡ƒª
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });
        for (int i = 0; i < buffer.size(); i++)
        {
            for (int j = 0; j < buffer[i].size(); j++)
                cout << buffer[i][j];
            cout << endl;
        }

        //≈–∂œ ‰”Æ
        if (map.getFoodCount() <= 0)
        {
            g_status = Win;
            return;
        }
        for (int k = 0; k < enemys.size(); k++)
            if (enemys[k].Catch(player))
            {
                g_status = Died;
                return;
            }
        this_thread::sleep_for(chrono::milliseconds(10));
    }
}

void player_run()
{
    while (g_status == Playing)
    {
        if (g_presskey != '\0')
            player.move();
        g_presskey = '\0';
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}

void enemys_run()
{
    while (g_status == Playing)
    {
        for (int k = 0; k < enemys.size(); k++)
            enemys[k].move();
        this_thread::sleep_for(chrono::milliseconds(700));
    }
}