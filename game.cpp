#include "game.h"

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
	BeginBatchDraw();
	loadimage(0, L"image/bg.jpg");
	loadimage(&img1, L"image/img1.jpg");
	loadimage(&img2, L"image/img2.jpg");
	loadimage(&img3, L"image/img3.jpg");

	/*����*/
	putimage(10, 10, &img1, SRCPAINT);
	putimage(10, 10, &img2, SRCAND);
	EndBatchDraw();

	memset(board, 0, sizeof(board));

	system("pause");

}

void PlayerMove(MOUSEMSG* msg)
{
	// ���ڴ�СΪ600x600��ÿ�����Ӵ�СΪ200x200
	int col = msg->x / 200;
	int line = msg->y / 200;
	if (board[col][line] == 0)
	{
		BeginBatchDraw();
		/*�û�����*/ 
		putimage(100, 100, &img1, SRCPAINT);
		putimage(100, 100, &img3, SRCAND);
		EndBatchDraw();
	}
}
void ComputerMove()
{
	// to do
}