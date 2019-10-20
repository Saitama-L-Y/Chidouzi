
#include "main.h"

Map map;
Player player;
vector<Enemy> enemys;
pressKey g_presskey;
GameSatus g_status = Start;

int main()
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO CursorInfo;
    GetConsoleCursorInfo(handle, &CursorInfo);//获取控制台光标信息
    CursorInfo.bVisible = false; //隐藏控制台光标
    SetConsoleCursorInfo(handle, &CursorInfo);//设置控制台光标状态

    thread t_keypress = thread(keyPress);

    int _mission = 1;               //选中的关卡
    int _select = 0;                //选中的菜单项
    while (g_status != Quit)
    {
        if (g_status == Start)
        {
            void menu(int &mission, int &select);
            menu(_mission, _select);
        }
        else if (g_status == Playing)
        {
            void play(int);
            play(_mission);
        }
        else if (g_status == Win)
        {
			void win(int& mission);
			win(_mission);
        }
        else if (g_status == Died)
        {
			void died();
			died();
        }
    }
    t_keypress.join();
    return 0;
}

void menu(int &mission, int &select)
{
    //system("cls");
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });
    cout << "使用W/S/A/D控制人物移动，躲避敌人的同时吃完所有食物获胜." << endl;
    string m[3] = {
        "1.start",
        "2.jump mission ",
        "3.quit"
    };
    switch (g_presskey.getPressKey())
    {
    case 'w':
    case 'W':
        select = select - 1 >= 0 ? --select : 0;
        break;
    case 's':
    case 'S':
        select = select + 1 <= 2 ? ++select : 2;
        break;
    case 'a':
    case 'A':
        if (select == 1)
            mission = mission - 1 >= 1 ? --mission : 1;
        break;
    case 'd':
    case 'D':
        if (select == 1)
            mission = mission + 1 <= 3 ? ++mission : 3;
        break;
    case '\r':
        if (select == 0) {
            mission = 1;
            g_status = Playing;
        }
        else if (select == 1)
            g_status = Playing;
        else if (select == 2)
            g_status = Quit;
        return;
    default:
        break;
    }
    m[1] += to_string(mission);
    for (int i = 0; i < 3; i++)
    {
        if (select == i)
            m[i] = "->" + m[i];
        else
            m[i] = "  " + m[i];
        cout << m[i] << endl;
    }
}

void play(int mission)
{
    switch (mission)
    {
    case 1:
        mission1(); break;
    case 2:
        mission2(); break;
    case 3:
        mission3(); break;
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

void win(int& mission)
{
	cout << "You win." << endl;
	if (mission < 3) {
		cout << "按下回车进入下一关." << endl;
		mission++;
		g_status = Playing;
	}
	else {
		cout << "按下回车返回菜单." << endl;
		mission = 1;
		g_status = Start;
	}
	while (_getch() != '\r');
	system("cls");
}

void died()
{
	cout << "You died." << endl;
	cout << "按下回车返回菜单." << endl;
	g_status = Start;
	while (_getch() != '\r');
	system("cls");
}