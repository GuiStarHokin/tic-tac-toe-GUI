#define _CRT_SECURE_NO_WARNINGS

#pragma once

#include <stdio.h>
#include <graphics.h>
#include <windows.h>
#include <mmsystem.h>
#include <time.h>

#pragma comment(lib, "winmm.lib")

enum
{
	Computer = -1,
	Player = 1,
};

/*8种胜利情况，每种胜利情况由3个坐标决定，每个坐标有行和列两个数据*/
int key[8][3][2] =
{
	// 行三种
	0,0 , 0,1 , 0,2,
	1,0 , 1,1 , 1,2,
	2,0 , 2,1 , 2,2,

	// 列三种
	0,0 , 0,1 , 0,2,
	1,0 , 1,1 , 1,2,
	2,0 , 2,1 , 2,2,

	// 正对角线
	0,0 , 1,1 , 2,2,

	// 斜对角线
	0,2 , 1,1 , 2,0
};

// 游戏的初始化
extern void InitGame();
extern void PlayerMove(MOUSEMSG* msg);
extern void ComputerMove();
extern int IsWin();