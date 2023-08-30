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
	int lines = msg->y / 200;
	int col = msg->x / 200;
	if (board[lines][col] == 0)
	{
		BeginBatchDraw();
		/*�û�����*/ 
		putimage(col * 200 + 10, lines * 200 + 10, &img1, SRCPAINT);
		putimage(col * 200 + 10, lines * 200 + 10, &img3, SRCAND);
		EndBatchDraw();
		board[lines][col] = Player;
	}
}
void ComputerMove()
{
	/*�򵥰�ĵ���*/

	/*��������Ӳ�Ӧ�÷�whileѭ������ȥ��
	����time(NULL)���ص��ǵ�ǰʱ���������
	����ں̵ܶ�ʱ���ڶ�ε���srand()������õ���ͬ������ֵ��
	�Ӷ��������ɵ������������ͬ��ʹ��ѭ���޷���ֹ*/

	/*����
	int lines = 0;
	int col = 0;
	srand((unsigned int)time(NULL)); 
	while (1)
	{
		lines = rand() % 3;
		col = rand() % 3;
		if (board[lines][col] == 0)
		{
			BeginBatchDraw();
			// ���Ժ���
			Sleep(2000);
			putimage(col * 200 + 10, lines * 200 + 10, &img1, SRCPAINT);
			putimage(col * 200 + 10, lines * 200 + 10, &img2, SRCAND);
			EndBatchDraw();
			board[lines][col] = Computer;
			break;
		}
	}
	*/

	// ������
	// ���˵�˼����ʽ���ô�������������Զ�����������ʽ˼��
	// �����������¹��ɣ�
	// 1.�����һ���壬�����м䣬��ô�ڶ��������ԣ���һ��Ҫ���ڽ��ϣ����򽫻����
	// 2.���������
	//		����Լ��ܹ�����Ӯ��������Ӯ
	//		����Է����Ͼ�ҪӮ�ˣ�����ֹ��
	//		�������

}

extern void PlayerWin()
{
	BeginBatchDraw();
	IMAGE player_win;
	loadimage(&player_win, L"image/win.jpg");
	putimage(0, 0, &player_win);
	EndBatchDraw();
}

extern void ComputerWin()
{
	BeginBatchDraw();
	IMAGE computer_win;
	loadimage(&computer_win, L"image/fail.jpg");
	putimage(0, 0, &computer_win);
	EndBatchDraw();
}

/*���˷���1����������0*/
extern int IsFull()
{
	int lines = 0;
	int col = 0;
	for (lines = 0, col = 0; lines < 3; lines++, col++)
	{
		if (board[lines][col] == 0)
		{
			return 0;
		}
	}
	if (lines == 3)
	{
		return 1;
	}
}

/*���Ӯ����1������Ӯ����-1��ƽ�ַ���2*/
int IsWin()
{
	/*
	����һ
	int lines = 0;
	int col = 0;

	// ����ͬ
	for (lines = 0; lines < 3; lines++)
	{
		if (board[lines][0] == board[lines][1] && board[lines][1] == board[lines][2] && board[lines][1] != 0)
		{
			if (board[lines][1] == 1)
			{
				PlayerWin();
				return 1;
			}
			else if (board[lines][1] == -1)
			{
				ComputerWin();
				return -1;
			}
		}
	} // end-for

	// ����ͬ
	lines = 0;
	for (col = 0; col < 3; col++)
	{
		if (board[0][col] == board[1][col] && board[1][col] == board[2][col] && board[1][col] != 0)
		{
			if (board[1][col] == 1)
			{
				PlayerWin();
				return 1;
			}
			else if (board[1][col] == -1)
			{
				ComputerWin();
				return -1;
			}
		}
	} // end-for

	// ���Խ���
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != 0)
	{
		if (board[1][1] == 1)
		{
			PlayerWin();
			return 1;
		}
		else if (board[1][1] == -1)
		{
			ComputerWin();
			return -1;
		}
	}

	// б�Խ���
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != 0)
	{
		if (board[1][1] == 1)
		{
			PlayerWin();
			return 1;
		}
		else if (board[1][1] == -1)
		{
			ComputerWin();
			return -1;
		}
	}

	// ƽ��
	int ret = IsFull();
	if (ret)
	{
		return 2;
	}
	else
	{
		return 3;
	}

	*/

	// ������
	int sum = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			sum += board[key[i][j][0]][key[i][j][1]];
		}
		if (sum == 3)
		{
			// ��Ӯ��
			PlayerWin();
		}
		else if (sum == -3)
		{
			// ����Ӯ��
			ComputerWin();
		}
	}
}