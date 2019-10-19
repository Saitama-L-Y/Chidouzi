
#include "main.h"

GameSatus g_status = Start;
char g_presskey = '\0';
Map map;
Player player;
vector<Enemy> enemys;

void play(int);
int main()
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO CursorInfo;
    GetConsoleCursorInfo(handle, &CursorInfo);//获取控制台光标信息
    CursorInfo.bVisible = false; //隐藏控制台光标
    SetConsoleCursorInfo(handle, &CursorInfo);//设置控制台光标状态

    thread t_keypress = thread(keyPress);

    int mission = 1;
    int select;    
	while (g_status != Quit)
	{
        if (g_status == Start)
        {
            cout << "Well Come." << endl;
            _getch();
            g_status = Playing;
			system("cls");
        }
        else if (g_status == Playing)
        {
            play(mission);
        }
        else if (g_status == Win)
        {
            cout << "You Win." << endl;
            _getch();
            g_status = Start;
        }
        else if (g_status == Died)
        {
            cout << "You Died." << endl;
            _getch();
            g_status = Start;
        }
	}
    t_keypress.join();
    return 0;
}

void play(int mission)
{
    switch (mission)
    {
    case 1:
        mission1(); break;
        //case 2:
        //    mission1(); break;
        //case 3:
        //    mission1(); break;
    default:
        break;
    }
    thread t_player = thread(player_run);
    thread t_enemys = thread(enemys_run);
    thread t_display = thread(display);
    t_player.join();
    t_enemys.join();
    t_display.join();

}