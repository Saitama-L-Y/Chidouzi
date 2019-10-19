#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <thread>
#include "Map.h"
#include "Enemy.h"
#include "Player.h"
#include "mission.h"
#include "control.h"

using namespace std;

enum GameSatus { Start, Playing, Win, Died, Quit };
extern GameSatus g_status;
extern char g_presskey;
extern Map map;
extern Player player;
extern vector<Enemy> enemys;