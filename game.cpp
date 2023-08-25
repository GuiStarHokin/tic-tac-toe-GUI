#include "game.h"

// 0:�հ� 1:��� -1:����
int board[3][3];
IMAGE img1, img2, img3;

void InitGame()
{
	// ������Ϸ����
	initgraph(600, 600, 0);

	// ���ô��ڱ���
	SetConsoleTitle(L"������");

	// ����һ������
	mciSendString(L"open Pallete.mp3", 0, 0, 0);
	mciSendString(L"play Pallete.mp3 repeat", 0, 0, 0);

	// ������Ϸ��Դ
	loadimage(0, L"image/bg.jpg");
	loadimage(&img1, L"image/img1.jpg");
	loadimage(&img2, L"image/img2.jpg");
	loadimage(&img3, L"image/img3.jpg");

	memset(board, 0, sizeof(board));

	//system("pause");

}

void PlayerMove(MOUSEMSG* msg)
{
	// ���ڴ�СΪ600x600��ÿ�����Ӵ�СΪ200x200
	int line = msg->y / 200;
	int col = msg->x / 200;
	if (board[line][col] == 0)
	{
		BeginBatchDraw();
		/*�û�����*/ 
		putimage(col * 200 + 10, line * 200 + 10, &img1, SRCPAINT);
		putimage(col * 200 + 10, line * 200 + 10, &img3, SRCAND);
		EndBatchDraw();
		board[line][col] = 1;
	}
}
void ComputerMove()
{
	/*�򵥰�ĵ���*/
	int line = 0;
	int col = 0;
	srand((unsigned int)time(NULL)); 
	/*��������Ӳ�Ӧ�÷�whileѭ������ȥ��
	����time(NULL)���ص��ǵ�ǰʱ���������
	����ں̵ܶ�ʱ���ڶ�ε���srand()������õ���ͬ������ֵ��
	�Ӷ��������ɵ������������ͬ��ʹ��ѭ���޷���ֹ*/
	while (1)
	{
		line = rand() % 3;
		col = rand() % 3;
		if (board[line][col] == 0)
		{
			BeginBatchDraw();
			/*���Ժ���*/
			putimage(col * 200 + 10, line * 200 + 10, &img1, SRCPAINT);
			putimage(col * 200 + 10, line * 200 + 10, &img2, SRCAND);
			EndBatchDraw();
			board[line][col] = -1;
			break;
		}
	}
}

void IsWin()
{
	int line = 0;
	int col = 0;
	
	// ����ͬ
	for (line = 0; line < 3; line++)
	{
		if (board[line][0] == board[line][1] && board[line][1] == board[line][2] && board[line][1] != 0)
		{
			if (board[line][1] == 1)
			{
				BeginBatchDraw();
				IMAGE player_win;
				loadimage(&player_win, L"win.jpg");
				putimage(0, 0, &player_win);
				EndBatchDraw();
			}
			else if (board[line][1] == 0)
			{
				BeginBatchDraw();
				IMAGE computer_win;
				loadimage(&computer_win, L"fail.jpg");
				putimage(0, 0, &computer_win);
				EndBatchDraw();
			}
		}
	}
}