#define _CRT_SECURE_NO_WARNINGS

#pragma once

#include <stdio.h>
#include <windows.h>
#include <mmsystem.h>
#include <time.h>

#pragma comment(lib, "winmm.lib")

// ���̵Ĵ�С
#define ROW 3
#define COL 3

// ���̵�����
int board[ROW][COL];
int g_cursorX, g_cursorY; // ��ǰ���λ��

void InitGame();
void PrintBoard();