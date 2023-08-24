#include "game.h"

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
	BeginBatchDraw();
	loadimage(0, L"image/bg.jpg");
	loadimage(&img1, L"image/img1.jpg");
	loadimage(&img2, L"image/img2.jpg");
	loadimage(&img3, L"image/img3.jpg");

	/*黑棋*/
	putimage(10, 10, &img1, SRCPAINT);
	putimage(10, 10, &img2, SRCAND);
	EndBatchDraw();

	memset(board, 0, sizeof(board));

	system("pause");

}

void PlayerMove(MOUSEMSG* msg)
{
	// 窗口大小为600x600，每个格子大小为200x200
	int col = msg->x / 200;
	int line = msg->y / 200;
	if (board[col][line] == 0)
	{
		BeginBatchDraw();
		/*用户白棋*/ 
		putimage(100, 100, &img1, SRCPAINT);
		putimage(100, 100, &img3, SRCAND);
		EndBatchDraw();
	}
}
void ComputerMove()
{
	// to do
}