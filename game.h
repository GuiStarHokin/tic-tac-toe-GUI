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

/*8��ʤ�������ÿ��ʤ�������3�����������ÿ���������к�����������*/
int key[8][3][2] =
{
	// ������
	0,0 , 0,1 , 0,2,
	1,0 , 1,1 , 1,2,
	2,0 , 2,1 , 2,2,

	// ������
	0,0 , 0,1 , 0,2,
	1,0 , 1,1 , 1,2,
	2,0 , 2,1 , 2,2,

	// ���Խ���
	0,0 , 1,1 , 2,2,

	// б�Խ���
	0,2 , 1,1 , 2,0
};

// ��Ϸ�ĳ�ʼ��
extern void InitGame();
extern void PlayerMove(MOUSEMSG* msg);
extern void ComputerMove();
extern int IsWin();