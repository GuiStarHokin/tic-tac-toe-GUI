#define _CRT_SECURE_NO_WARNINGS

#pragma once

#include <stdio.h>
#include <windows.h>
#include <mmsystem.h>
#include <time.h>

#pragma comment(lib, "winmm.lib")

// 棋盘的大小
#define ROW 3
#define COL 3

// 棋盘的数据
int board[ROW][COL];
int g_cursorX, g_cursorY; // 当前光标位置

void InitGame();
void PrintBoard();