#define _CRT_SECURE_NO_WARNINGS

#pragma once

#include <stdio.h>
#include <graphics.h>
#include <windows.h>
#include <mmsystem.h>
#include <time.h>

#pragma comment(lib, "winmm.lib")

// 0:空白 1:玩家 -1:电脑
int board[3][3];
IMAGE img1, img2, img3;

// 游戏的初始化
extern void InitGame();
extern void PlayerMove(MOUSEMSG* msg);
extern void ComputerMove();