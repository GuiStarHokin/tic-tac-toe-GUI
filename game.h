#define _CRT_SECURE_NO_WARNINGS

#pragma once

#include <stdio.h>
#include <graphics.h>
#include <windows.h>
#include <mmsystem.h>
#include <time.h>

#pragma comment(lib, "winmm.lib")

// 0:�հ� 1:��� -1:����
int board[3][3];
IMAGE img1, img2, img3;

// ��Ϸ�ĳ�ʼ��
extern void InitGame();
extern void PlayerMove(MOUSEMSG* msg);
extern void ComputerMove();