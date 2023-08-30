#include "game.h"

// 0:空白 1:玩家 -1:电脑
int board[3][3];
IMAGE img1, img2, img3;

void InitGame()
{
	// 创建游戏窗口
	initgraph(600, 600, 0);

	// 设置窗口标题
	SetConsoleTitle(L"三子棋");

	// 播放一点音乐
	mciSendString(L"open Pallete.mp3", 0, 0, 0);
	mciSendString(L"play Pallete.mp3 repeat", 0, 0, 0);

	// 加载游戏资源
	loadimage(0, L"image/bg.jpg");
	loadimage(&img1, L"image/img1.jpg");
	loadimage(&img2, L"image/img2.jpg");
	loadimage(&img3, L"image/img3.jpg");

	memset(board, 0, sizeof(board));

	//system("pause");

}

void PlayerMove(MOUSEMSG* msg)
{
	// 窗口大小为600x600，每个格子大小为200x200
	int lines = msg->y / 200;
	int col = msg->x / 200;
	if (board[lines][col] == 0)
	{
		BeginBatchDraw();
		/*用户白棋*/ 
		putimage(col * 200 + 10, lines * 200 + 10, &img1, SRCPAINT);
		putimage(col * 200 + 10, lines * 200 + 10, &img3, SRCAND);
		EndBatchDraw();
		board[lines][col] = Player;
	}
}
void ComputerMove()
{
	/*简单版的电脑*/

	/*随机数种子不应该放while循环里面去，
	由于time(NULL)返回的是当前时间的秒数，
	因此在很短的时间内多次调用srand()函数会得到相同的种子值，
	从而导致生成的随机数序列相同，使得循环无法终止*/

	/*屏蔽
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
			// 电脑黑棋
			Sleep(2000);
			putimage(col * 200 + 10, lines * 200 + 10, &img1, SRCPAINT);
			putimage(col * 200 + 10, lines * 200 + 10, &img2, SRCAND);
			EndBatchDraw();
			board[lines][col] = Computer;
			break;
		}
	}
	*/

	// 方法二
	// 把人的思考方式，用代码表达出来，并自动按照整个方式思考
	// 三子棋有以下规律：
	// 1.如果第一步棋，走在中间，那么第二步（电脑），一定要走在角上，否则将会输掉
	// 2.其他情况：
	//		如果自己能够马上赢，就马上赢
	//		如果对方马上就要赢了，就阻止他
	//		否则：随机

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

/*满了返回1，不满返回0*/
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

/*玩家赢返回1，电脑赢返回-1，平局返回2*/
int IsWin()
{
	/*
	方法一
	int lines = 0;
	int col = 0;

	// 行相同
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

	// 列相同
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

	// 正对角线
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

	// 斜对角线
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

	// 平局
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

	// 方法二
	int sum = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			sum += board[key[i][j][0]][key[i][j][1]];
		}
		if (sum == 3)
		{
			// 人赢了
			PlayerWin();
		}
		else if (sum == -3)
		{
			// 电脑赢了
			ComputerWin();
		}
	}
}