#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <thread>
#include <string>
#include "Map.h"
#include "Enemy.h"
#include "Boss.h"
#include "Player.h"
#include "mission.h"
#include "control.h"

using namespace std;

enum GameSatus { Start, Playing, Win, Died, Quit };
extern GameSatus g_status;
extern pressKey g_presskey;
extern Map map;
extern Player player;
extern vector<Enemy*> enemys;