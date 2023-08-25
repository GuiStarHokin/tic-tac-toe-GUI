#define _CRT_SECURE_NO_WARNINGS

#pragma once

#include <stdio.h>
#include <graphics.h>
#include <windows.h>
#include <mmsystem.h>
#include <time.h>

#pragma comment(lib, "winmm.lib")

// 游戏的初始化
extern void InitGame();
extern void PlayerMove(MOUSEMSG* msg);
extern void ComputerMove();
extern void IsWin();