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
	int line = msg->y / 200;
	int col = msg->x / 200;
	if (board[line][col] == 0)
	{
		BeginBatchDraw();
		/*用户白棋*/ 
		putimage(col * 200 + 10, line * 200 + 10, &img1, SRCPAINT);
		putimage(col * 200 + 10, line * 200 + 10, &img3, SRCAND);
		EndBatchDraw();
		board[line][col] = 1;
	}
}
void ComputerMove()
{
	/*简单版的电脑*/
	int line = 0;
	int col = 0;
	srand((unsigned int)time(NULL)); 
	/*随机数种子不应该放while循环里面去，
	由于time(NULL)返回的是当前时间的秒数，
	因此在很短的时间内多次调用srand()函数会得到相同的种子值，
	从而导致生成的随机数序列相同，使得循环无法终止*/
	while (1)
	{
		line = rand() % 3;
		col = rand() % 3;
		if (board[line][col] == 0)
		{
			BeginBatchDraw();
			/*电脑黑棋*/
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
	
	// 行相同
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